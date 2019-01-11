#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Stack.h"
#include <string.h>

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
			//大于才交换，等于不交换
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
	int min = 0;
	int max = n-1;
	//每趟选一个大的、一个小的
	while (min < max)
	{
		for (int i = min; i <= max; ++i)
		{
			//找max时，让相等的两个数后面一个作为max被交换到最后
			if (arr[i] >= arr[max])
			{
				Swap(&arr[i], &arr[max]);
			}
			//找min时，让相等的两个数前面一个作为min被交换到前面
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
			//等于时不交换，保持稳定性
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

//三数取中法
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

void _MergeSort(int *arr, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);

	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);

	//[left, mid]  [mid+1, right]
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int ret = left;
	//两个排好序的区间归并
	while (begin1 <= end1 && begin2 <= end2)
	{
		//等于时为保证稳定性，先插入前面一个
		if (arr[begin1] <= arr[begin2])
		{
			tmp[left++] = arr[begin1];
			begin1++;
		}
		else
		{
			tmp[left++] = arr[begin2];
			begin2++;
		}
	}
	//当其中一个区间遍历完，把另一个区间中剩余元素都拷贝至tmp中
	while (begin1 <= end1)
	{
		tmp[left++] = arr[begin1];
		begin1++;
	}
	while (begin2 <= end2)
	{
		tmp[left++] = arr[begin2];
		begin2++;
	}
	//将tmp中归并好的有序序列拷回原数组
	while (ret <= right)
	{
		arr[ret] = tmp[ret];
		ret++;
	}
}

void MergeSort(int *arr, int n)
{
	//需要新开辟一个同等大小的空间用于两个区间的归并
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

void CountSort(int *arr, int n)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int size = max - min + 1;
	int *tmp = (int *)malloc(sizeof(int)* size);
	memset(tmp, 0, sizeof(int) * size);
	int begin = 0;
	while (begin < n)
	{
		tmp[arr[begin] - min]++;
		++begin;
	}
	begin = 0;
	int left = 0;
	while (begin < size)
	{
		while (tmp[begin]-- > 0)
		{
			arr[left++] = begin+1;
		}
		begin++;
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
	//int arr[] = { 5, 9, 2, 6, 5, 7, 3, 8, 4, 1 };
	//int arr[] = { 5, 8, 7, 6, 9, 5, 4, 3, 2, 1 };
	int arr[] = { 6, 5 };

	int size = sizeof(arr) / sizeof(arr[0]);
	//int begin = clock();
	//ShellSort(arr, size);
	////InsertSort(arr, size);
	//int end = clock();
	//printf("%d\n", end - begin);
	SelectSort(arr, size);
	//HeapSort(arr, size);
	//BubbleSort(arr, size);
	//QuickSort(arr, 0, size - 1);
	//QuickSortNonR(arr, 0, size - 1);
	//MergeSort(arr, size);
	//CountSort(arr, size);

	//PartSort(arr, 0, size - 1);
	ArrayPrint(arr, size);
	//printf("%d\n", GetMid(arr, 0, size - 1));
}
