#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode *_next;
	struct ListNode *_prev;
} ListNode;

typedef struct List
{
	ListNode *_head;
} List;

void ListInit(List *plist);
void ListDestory(List *plist);
void ListPrint(List *plist);
ListNode *CreateListNode(LTDataType x);
void ListPushBack(List *plist, LTDataType x);
void ListPopBack(List *plist);
void ListPushFront(List *plist, LTDataType x);
void ListPopFront(List *plist);

ListNode *ListFind(List *plist, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x);
void ListErase(ListNode *pos);

void ListReverse(List *plist);

void ListTest();

#endif //__LIST_H__