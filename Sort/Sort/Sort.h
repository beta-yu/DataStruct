#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Stack.h"

void ArrayPrint(int *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//实现升序排列
void InsertSort(int *arr, int n)
{
	int end = 0;
	int tmp = 0;
	for (end = 0; end < n - 1; ++end)
	{
		tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int *arr, int n)
{
	int gap = n;
	while (gap >= 1)  //控制gap的大小
	{
		//一般设置gap为：
		gap = gap / 3 + 1; //逐渐缩小，直到1
		int i = 0;
		//插入排序
		for (i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = 0;
			tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
		if (gap == 1)
			break;
	}
}

void SelectSort(int *arr, int n)
{
	int max = n - 1;
	int min = 0;
	while (min <= max)
	{
		for (int i = min; i < max; ++i)
		{
			if (arr[i] > arr[max])
			{
				Swap(&arr[i], &arr[max]);
			}
			if (arr[i] < arr[min])
			{
				Swap(&arr[i], &arr[min]);
			}
		}
		min++;
		max--;
	}
	
}

void AdjustDown(int *arr, int n, int i)
{
	//一趟向下调整，需保证左右子树都是大堆
	int parent = i;
	int child = 2 * i + 1;
	while (child < n)
	{
		//让最大元素在左孩子
		if (arr[child] < arr[child + 1] && child+1 < n)
		{
			++child;
		}
		//如果父亲小于左孩子，交换，向下走
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *arr, int n)
{
	int root = (n - 1 - 1) / 2;
	//构建大堆
	while (root >= 0)
	{
		AdjustDown(arr, n, root);
		root--;
	}
	//将堆顶元素与最后一个元素交换，并控制数组可访问长度，保存到末尾的最大元素不能再被调整
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void BubbleSort(int *arr, int n)
{
	int end = n;
	while (end > 1)
	{
		int flag = 0;
		for (int cur = 0; cur < end - 1; ++cur)
		{
			if (arr[cur] > arr[cur + 1])
			{
				flag = 1;
				Swap(&arr[cur], &arr[cur + 1]);
			}
		}
		if (flag == 0)
			break;
	}
}

int GetMid(int *arr, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[begin] > arr[end])
			return begin;
		else if (arr[end] > arr[mid])
			return mid;
		else
			return end;
	}
}

/*
PartSort()负责将数组中大于key的放在key的右边，小于key的放在key的左边
key通过三数取中法（GetMid）获得，使得key的大小尽量接近中位数
*/
int PartSort1(int *arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

	int ret = begin;
	int key = arr[begin];
	while (begin < end)
	{
		//先从右开始找小
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		//再从左开始找大
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		//交换
		if (begin < end)
			Swap(&arr[begin], &arr[end]);
	}
	//当前值给开始位置
	arr[ret] = arr[begin];
	//中间值放在当前位置(相遇处)
	arr[begin] = key;

	return begin;
}

int PartSort2(int *arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

	int key = arr[begin];
	//起始begin为坑
	while (begin < end)
	{
		//从左开始找比key小的，将该数放到当前坑中，该位置变为坑
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		arr[begin] = arr[end];

		//再从右开始找比key大的，将该数放到当前坑中，该位置变为坑
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}

	arr[begin] = key;
	return begin;
}

//前后指针法
int PartSort3(int *arr, int begin, int end)
{
	int mid = GetMid(arr, begin, end);
	Swap(&arr[begin], &arr[mid]);

	int key = arr[begin];
	int prev = begin;
	int cur = prev + 1;
	//cur找到小于key的就与prev交换
	while (cur <= end)
	{
		//prev走过的都是小于key的
		if (arr[cur] < key)
		{
			++prev;
			if (prev != cur)
			{
				Swap(&arr[prev], &arr[cur]);
			}
		}
		++cur;
	}
	//将最终prev处与起始处(key)互换
	Swap(&arr[prev], &arr[begin]);
	return prev;
}

void QuickSort(int *arr, int left, int right)
{
	if (left >= right)
		return;
	int mid;
	
	if (left < right)
	{
		if (right - left > 5)
		{
			mid = PartSort3(arr, left, right);

			QuickSort(arr, left, mid - 1);
			QuickSort(arr, mid + 1, right);
		}
		//减少递归层次，小区间直接使用插入排序
		else
		{
			InsertSort(arr + left, right - left + 1);
		}
	}
}

//非递归实现快排
void QuickSortNonR(int *arr, int left, int right)
{
	Stack *st = (Stack *)malloc(sizeof(Stack));
	StackInit(st);
	//将区间两端点压栈，注意顺序一致，压栈和出栈配合
	StackPush(st, right);
	StackPush(st, left);
	while (StackEmpty(st) != 0)
	{
		int begin = StackTop(st);
		StackPop(st);
		int end = StackTop(st);
		StackPop(st);
		int div = PartSort1(arr, begin, end);

		//[begin, div-1]
		if (begin < div-1)
		{
			StackPush(st, div - 1);
			StackPush(st, begin);
		}

		//[div+1, end]
		if (div+1 < end)
		{
			StackPush(st, end);
			StackPush(st, div + 1);
		}
	}
}

void SortTest()
{
	/*srand(time(0));
	int size = 10000;
	int *arr = (int *)malloc(sizeof(int)* size);
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		arr[i] = rand();
	}*/
	int arr[] = { 5, 9, 2, 6, 5, 7, 3, 8, 4, 1 };
	//int arr[] = { 5, 8, 7, 6, 9, 5, 4, 3, 2, 1 };
	//int arr[] = { 5, 6 };

	int size = sizeof(arr) / sizeof(arr[0]);
	//int begin = clock();
	//ShellSort(arr, size);
	////InsertSort(arr, size);
	//int end = clock();
	//printf("%d\n", end - begin);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	//BubbleSort(arr, size);
	//QuickSort(arr, 0, size - 1);
	QuickSortNonR(arr, 0, size - 1);

	//PartSort(arr, 0, size - 1);
	ArrayPrint(arr, size);
	//printf("%d\n", GetMid(arr, 0, size - 1));
}
