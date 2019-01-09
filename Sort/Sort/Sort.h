#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	int arr[] = { 9, 5, 2, 6, 5, 7, 3, 8, 4, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//int begin = clock();
	//ShellSort(arr, size);
	////InsertSort(arr, size);
	//int end = clock();
	//printf("%d\n", end - begin);
	//SelectSort(arr, size);
	HeapSort(arr, size);
	ArrayPrint(arr, size);
}
