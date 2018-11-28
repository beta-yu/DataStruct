#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode *_next;
}SListNode;

typedef struct SList
{
	SListNode *_head;
}SList;

void SListInit(SList *plist);
void SListDestory(SList *plist);

void SListPrint(SList *plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList *plist, SLTDataType x);

void SListInsertAfter(SListNode *pos, SLTDataType x);
SListNode* SListFind(SList *plist, SLTDataType x);
void SListPopFront(SList *plist);
void SListPopBack(SList *plist);
void SListRemove(SList *plist, SLTDataType x);


void SListTest();

#endif //__SLIST_H__