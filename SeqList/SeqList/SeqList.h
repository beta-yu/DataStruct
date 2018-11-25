#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *array;
	size_t size;
	size_t capacity;
} SeqList;

void SeqListInit(SeqList *ps, size_t capacity);
void SeqListDestory(SeqList *ps);

void CheckCapacity(SeqList *ps);

int SeqListFind(SeqList *ps, SLDataType x);
void SeqListInsert(SeqList *ps, size_t pos, SLDataType x);
void SeqListErase(SeqList *ps, size_t pos);

void SeqListPushBack(SeqList *ps, SLDataType x);
void SeqListPushFront(SeqList *ps, SLDataType x);
void SeqListPopBack(SeqList *ps);
void SeqListPopFront(SeqList *ps);

void SeqListModify(SeqList *ps, size_t pos, SLDataType x);
void SeqListBubbleSort(SeqList *ps);
int SeqListBinaryFind(SeqList *ps, SLDataType x);

void SeqListRemoveAll(SeqList* ps, SLDataType x);
void SeqListPrint(SeqList *ps);

void SeqListTest(SeqList *ps);

#endif //__SEQLIST_H__