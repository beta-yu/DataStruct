#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "common.h"

typedef BTNode * QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode *_next;
}QNode;

typedef struct Queue
{
	QNode *_head;
	QNode *_tail;
}Queue;

void QueueInit(Queue *q);
void QueueDestory(Queue *q);
void QueuePush(Queue *q, QDataType x);
void QueuePop(Queue *q);
int QueueSize(Queue *q);
int QueueEmpty(Queue *q);
QDataType QueueFront(Queue *q);


#endif //__QUEUE_H__