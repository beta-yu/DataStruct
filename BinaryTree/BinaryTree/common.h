#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BTNode
{
	BTDataType _data;
	struct BTNode *_left;
	struct BTNode *_right;
} BTNode;

#endif //__COMMON_H__