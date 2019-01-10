#ifndef __STACK_H__
#define __STACK_H__

#include "common.h"

typedef int SDataType;
typedef struct Stack
{
	SDataType *_arr;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack *s);
void StackDestory(Stack *s);
void StackPush(Stack *s, SDataType x);
SDataType StackTop(Stack *s);
void StackPop(Stack *s);
int StackEmpty(Stack *s);
void StackTest();

#endif //__STACK_H__
