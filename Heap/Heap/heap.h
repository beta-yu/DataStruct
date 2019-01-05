#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType *_array;
	size_t _size;
	size_t _capacity;
} Heap;

void HeapInit(Heap *hp, HPDataType *a, size_t n);
void HeapDestory(Heap *hp);
void HeapPrint(Heap *hp);
void AdjustDown(HPDataType *a, size_t n, size_t root);
void Swap(HPDataType *a, HPDataType *b);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
void AdjustUp(HPDataType *a, size_t child);
void HeapSort(int *a, int n);
void TopK(HPDataType *a, int k, int n);

void HeapTest();

#endif //__HEAP_H__