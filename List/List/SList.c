#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void SListInit(SList *plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList *plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		SListNode *prev = plist->_head;
		SListNode *tail = plist->_head->_next;
		while (prev->_next)
		{
			free(prev);
			prev = tail;
			tail = tail->_next;
		}
		free(prev);
		plist->_head = NULL;
	}
}

void SListPrint(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void SListPushFront(SList *plist, SLTDataType x)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = plist->_head;
	plist->_head = node;
}

void SListInsertAfter(SListNode *pos, SLTDataType x)
{
	assert(pos);
	SListNode *node = BuySListNode(x);
	node->_next = pos->_next;
	pos->_next = node;
}

SListNode* SListFind(SList *plist, SLTDataType x)
{
	assert(plist);

	SListNode *dst = plist->_head;
	while (dst)
	{
		if (dst->_data == x)
		{
			return dst;
		}
		else
		{
			dst = dst->_next;
		}
	}
	return NULL;
}

void SListPopFront(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head->_next;
	free(plist->_head);
	plist->_head = cur;
}

void SListPopBack(SList *plist)
{
	assert(plist);
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
	}
	else
	{
		SListNode *prev = plist->_head;
		SListNode *tail = plist->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}

void SListRemove(SList *plist, SLTDataType x)
{
	assert(plist);
	SListNode *cur = plist->_head;
	if (cur->_data == x)
	{
		plist->_head = cur->_next;
		free(cur);
	}
	else
	{
		while (cur->_next)
		{
			if (cur->_next->_data == x)
			{
				SListNode *dst = cur->_next;
				cur->_next = dst->_next;
				free(dst);
				return;
			}
			cur = cur->_next;
		}
	}
}

void SListTest()
{
	SList *plist = (SList *)malloc(sizeof(SList));
	SListInit(plist);
	SListPushFront(plist, 1);
	SListPushFront(plist, 2);
	SListPushFront(plist, 3);
	SListNode *cur = SListFind(plist, 1);
	SListInsertAfter(cur, 0);
	SListPrint(plist);
	//SListPopFront(plist);
	/*SListPopBack(plist);*/
	SListRemove(plist, 1);

	SListPrint(plist);
	SListDestory(plist);
}
