#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SeqList *ps, size_t capacity)
{
	assert(ps);
	ps->array = (SLDataType *)malloc(sizeof(SLDataType)* capacity);
	ps->size = 0;
	ps->capacity = capacity;
}

void SeqListDestory(SeqList *ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void CheckCapacity(SeqList *ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDataType *ret = realloc(ps->array, (ps->capacity) * 2 * sizeof(SLDataType));
		if (ret != NULL)
		{
			ps->array = ret;
			ps->capacity *= 2;
		}
	}

}

int SeqListFind(SeqList *ps, SLDataType x)
{
	assert(ps);
	int begin = 0;
	for (begin = 0; begin < ps->size; ++begin)
	{
		if (ps->array[begin] == x)
		{
			return begin;
		}
	}
	return -1;
}

void SeqListInsert(SeqList *ps, size_t pos, SLDataType x)
{
	assert(ps && pos <= ps->size);
	CheckCapacity(ps);

	int end = ps->size;
	while (end > pos)
	{
		ps->array[end] = ps->array[end - 1];
		--end;
	}
	ps->array[pos] = x;
	ps->size++;
}

void SeqListPushBack(SeqList *ps, SLDataType x)
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList *ps, SLDataType x)
{
	SeqListInsert(ps, 0, x);
}

void SeqListErase(SeqList *ps, size_t pos)
{
	assert(ps && pos < ps->size);

	size_t begin = pos;
	while (begin < ps->size - 1)
	{
		ps->array[begin] = ps->array[begin + 1];
		++begin;
	}
	--(ps->size);

}

void SeqListPopBack(SeqList *ps)
{
	SeqListErase(ps, ps->size - 1);
}

void SeqListPopFront(SeqList *ps)
{
	SeqListErase(ps, 0);
}

void SeqListModify(SeqList *ps, size_t pos, SLDataType x)
{
	assert(ps);
	ps->array[pos] = x;
}

void SeqListBubbleSort(SeqList *ps)
{
	assert(ps);

	int i = 0;
	int j = 0;
	int flag = 0;
	for (j = 0; j < ps->size - 1 - 1; j++)
	{
		for (i = 0; i < ps->size - 1 - j; ++i)
		{
			if (ps->array[i] > ps->array[i + 1])
			{
				flag = 1;
				SLDataType tmp = ps->array[i + 1];
				ps->array[i + 1] = ps->array[i];
				ps->array[i] = tmp;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

int SeqListBinaryFind(SeqList *ps, SLDataType x)
{
	assert(ps);
	int begin = 0;
	int end = ps->size;
	/*左闭右开*/
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (ps->array[mid] == x)
		{
			return mid;
		}
		else if (ps->array[mid] > x)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return -1;
}

void SeqListPrint(SeqList *ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

// 要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll_1(SeqList* ps, SLDataType x)
{
	assert(ps);

	SLDataType *left = &(ps->array[0]);
	SLDataType *right = &(ps->array[ps->size - 1]);
	int count = 0;
	while (left < right)
	{
		while (*left != x && left < right)
		{
			++left;
		}
		while (*right == x && left < right)
		{
			--right;
			count++;
		}
		if (*left == x && *right != x)
		{
			SLDataType tmp = *left;
			*left = *right;
			*right = tmp;
			count++;
			--right;
		}
		
	}
	ps->size -= count;
} 

void SeqListRemoveAll_2(SeqList* ps, SLDataType x)
{
	assert(ps);

	SLDataType *ptr = &(ps->array[0]);
	int i = 0;
	int count = 0;
	for (i = 0; i < ps->size; ++i)
	{
		if (ps->array[i] != x)
		{
			*ptr++ = ps->array[i];
		}
		else
		{
			++count;
		}
	}
	ps->size -= count;
}


void SeqListTest(SeqList *ps)
{
	
	SeqListInit(ps, 2);

	/*SeqListInsert(ps, 0, 0);
	SeqListInsert(ps, 0, 1);
	SeqListPushBack(ps, 2);
	SeqListPushFront(ps, -1);
	SeqListPrint(ps);*/
	/*SeqListPopBack(ps);
	SeqListPopFront(ps);*/

	//SeqListModify(ps, 2, 8);
	SeqListPushBack(ps, 0);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 5);
	SeqListPushBack(ps, 6);
	SeqListPushBack(ps, 7);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 2);

	//SeqListBubbleSort(ps);
	SeqListPrint(ps);

	/*printf("%d\n", SeqListBinaryFind(ps, 0));
	printf("%d\n", SeqListBinaryFind(ps, 1));
	printf("%d\n", SeqListBinaryFind(ps, 2));
	printf("%d\n", SeqListBinaryFind(ps, 3));
	printf("%d\n", SeqListBinaryFind(ps, 4));
	printf("%d\n", SeqListBinaryFind(ps, 5));
	printf("%d\n", SeqListBinaryFind(ps, 6));
	printf("%d\n", SeqListBinaryFind(ps, 7));
	printf("%d\n", SeqListBinaryFind(ps, 8));
	printf("%d\n", SeqListBinaryFind(ps, 9));
	printf("%d\n", SeqListBinaryFind(ps, 10));*/

	SeqListRemoveAll_1(ps, 2);
	SeqListPrint(ps);

	//printf("%d\n", SeqListFind(ps, -1));

	SeqListDestory(ps);
}