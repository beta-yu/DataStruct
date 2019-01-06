#include "Queue.h"

void QueueInit(Queue *q)
{
	assert(q);
	q->_head = NULL;
	q->_tail = NULL;
}

void QueueDestory(Queue *q)
{
	assert(q);
	QNode *cur = q->_head;
	while (cur)
	{
		QNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}

void QueuePush(Queue *q, QDataType x)
{
	assert(q);
	QNode *newnode = (QNode *)malloc(sizeof(QNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (q->_head == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else
	{
		q->_tail->_next = newnode;
		q->_tail = q->_tail->_next;
	}
}

void QueuePop(Queue *q)
{
	assert(q);
	QNode *ret = q->_head;
	q->_head = q->_head->_next;
	free(ret);
	if (ret == NULL)
	{
		q->_tail = NULL;
	}
}

int QueueSize(Queue *q)
{
	assert(q);
	int size = 0;
	QNode *cur = q->_head;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

int QueueEmpty(Queue *q)
{
	assert(q);
	return q->_head == NULL ? 1 : 0;
}

QDataType QueueFront(Queue *q)
{
	assert(q);
	return q->_head->_data;
}
