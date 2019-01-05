#include "Queue.h"

QNode *QueueInit(QNode *qn)
{
	assert(qn);
	qn->_next = NULL;
}

void QueuePush()
{

}

void QueueTest()
{
	QNode *qn = (QNode *)malloc(sizeof(QNode));
	QueueInit(qn);
}