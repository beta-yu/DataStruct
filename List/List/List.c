#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void ListInit(List *plist)
{
	assert(plist);
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List *plist)
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		struct ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPrint(List *plist)
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *cur = head->_next;
	printf("<-head->");
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

ListNode *CreateListNode(LTDataType x)
{
	ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}

void ListPushBack(List *plist, LTDataType x)
{
	assert(plist);
	/*ListNode *newnode = CreateListNode(x);
	ListNode *head = plist->_head;
	head->_prev->_next = newnode;
	newnode->_prev = head->_prev;
	newnode->_next = head;
	head->_prev = newnode;*/
	ListInsert(plist->_head, x);
}

void ListPopBack(List *plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	/*ListNode *tail = plist->_head->_prev;
	tail->_prev->_next = plist->_head;
	plist->_head->_prev = tail->_prev;
	free(tail);*/
	ListErase(plist->_head->_prev);
}

void ListPushFront(List *plist, LTDataType x)
{
	assert(plist);
	/*ListNode *newnode = CreateListNode(x);
	ListNode *next = plist->_head->_next;
	newnode->_next = next;
	next->_prev = newnode;
	plist->_head->_next = newnode;
	newnode->_prev = plist->_head;*/
	ListInsert(plist->_head->_next, x);
}

void ListPopFront(List *plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	/*ListNode *first = plist->_head->_next;
	plist->_head->_next = first->_next;
	first->_next->_prev = plist->_head;
	free(first);*/
	ListErase(plist->_head->_next);
}

ListNode *ListFind(List *plist, LTDataType x)
{
	assert(plist);
	ListNode *cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}

//在pos之前插入
void ListInsert(ListNode *pos, LTDataType x)
{
	assert(pos);
	ListNode *newnode = CreateListNode(x);
	ListNode *prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	pos->_prev = newnode;
	newnode->_next = pos;
}

void ListErase(ListNode *pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void ListReverse_1(List *plist)
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		ListNode *ptmp = cur->_prev;
		cur->_prev = cur->_next;
		cur->_next = ptmp;

		cur = cur->_prev;
	}
	ListNode *ptmp = head->_prev;
	head->_prev = head->_next;
	head->_next = ptmp;
}

void ListReverse_2(List *plist)
{
	assert(plist != NULL);
	ListNode *begin = plist->_head->_next;
	ListNode *end = plist->_head->_prev;

	while (begin != end && end->_next != begin)
	{
		LTDataType tmp = begin->_data;
		begin->_data = end->_data;
		end->_data = tmp;

		begin = begin->_next;
		end = end->_prev;
	}
}

void ListTest()
{
	List list;
	ListInit(&list);

	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPrint(&list);

	/*ListPopBack(&list);
	ListPrint(&list);

	ListPushFront(&list, 0);
	ListPrint(&list);

	ListPopFront(&list);*/

	//ListErase(ListFind(&list, 1));
	//ListReverse_1(&list);
	ListReverse_2(&list);

	ListPrint(&list);
	ListDestory(&list);
}