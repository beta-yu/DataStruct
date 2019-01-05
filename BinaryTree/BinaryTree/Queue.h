#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "common.h"

typedef char QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode *_next;
}QNode;

QNode *QueueInit(QNode *qn);
void QueuePush();

void QueueTest();
#endif //__QUEUE_H__