#include "heap.h"

void Swap(HPDataType *a, HPDataType *b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整
void AdjustDown(HPDataType *a, size_t n, size_t root)
{
	size_t parent = root;
	size_t child = 2 * parent + 1;
	//每次都遍历到叶子节点
	while (child < n)
	{
		//小根堆
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap *hp, HPDataType *a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType *)malloc(sizeof(HPDataType)* n);
	hp->_capacity = hp->_size = n;
	memcpy(hp->_array, a, sizeof(HPDataType)* n);

	//从倒数第一个非叶子节点开始调整堆，直到堆顶
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}

void HeapDestory(Heap *hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapPrint(Heap *hp)
{
	assert(hp);
	size_t i = 0;
	for (i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

//向上调整
void AdjustUp(HPDataType *a, size_t child)
{
	assert(a);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		//小根堆
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap *hp, HPDataType x)
{
	//插入到尾部(最后一个叶子节点)
	if (hp->_size == hp->_capacity)
	{
		hp->_array = (HPDataType *)realloc(hp->_array, sizeof(HPDataType) * hp->_capacity * 2);
		hp->_capacity *= 2;
	}
	hp->_array[hp->_size] = x;
	hp->_size++;

	//从最后一个叶子节点开始调整堆
	AdjustUp(hp->_array, hp->_size - 1);
}

void HeapPop(Heap *hp)
{
	assert(hp);
	//将第一个元素(堆顶元素)与最后一个元素互换
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}

//小堆，降序排
void HeapSort(int *a, int n)
{
	int i = 0;
	//构建小堆
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		//每次将堆顶元素交换到末尾，调整时控制数组可访问的长度
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//大top，构建有K个元素的小堆
void TopK(HPDataType *a, int k, int n)
{
	assert(a);
	//构建k个元素的小堆
	Heap hp;
	//用数组前k个元素初始化堆
    HeapInit(&hp, a, k);
	int i = 0;
	//从第k+1个元素和堆顶元素比较，大于堆顶元素的与堆顶元素交换，再从堆顶向下调整，直至遍历完所有元素
	for (i = k; i < n; ++i)
	{
		if (a[i] > hp._array[0])
		{
			Swap(&a[i], &(hp._array[0]));
			AdjustDown(hp._array, k, 0);
		}
	}
	HeapPrint(&hp);
}

void HeapTest()
{
//	Heap hp;
	int arr[100] = { 0 };
	/*HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 0);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);*/
	for (int i = 0; i < 100; ++i)
	{
		arr[i] = 100 - i;
	}
	arr[1] = 101;
	arr[11] = 102;
	arr[34] = 103;
	arr[51] = 104;
	arr[95] = 105;
	arr[29] = 106;
	arr[57] = 107;
	arr[84] = 108;
	arr[7] = 109;
	arr[61] = 110;

	TopK(arr, 10, 100);
	/*int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr, sz);
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	//HeapDestory(&hp);
}