#include "Stack.h"

void StackInit(Stack *s)
{
	assert(s);
	s->_arr = NULL;
	s->_capacity = 0;
	s->_top = 0;
}

void StackDestory(Stack *s)
{
	assert(s);
	free(s->_arr);
	s->_arr = NULL;
	s->_capacity = 0;
	s->_top = 0;
}

void StackPush(Stack *s, SDataType x)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		int newcapacity = s->_capacity == 0 ? 4 : s->_capacity * 2;
		s->_arr = (SDataType *)realloc(s->_arr, sizeof(SDataType) * newcapacity);
		assert(s->_arr != NULL);
		s->_capacity = newcapacity;
	}
	s->_arr[s->_top] = x;
	++(s->_top);
}

SDataType StackTop(Stack *s)
{
	assert(s && s->_top != 0);
	return s->_arr[s->_top - 1];
}

void StackPop(Stack *s)
{
	assert(s && s->_top != 0);
	--(s->_top);
}

int StackEmpty(Stack *s)
{
	assert(s);
	return s->_top == 0 ? 0 : 1;
}

void StackTest()
{
	Stack *s = (Stack *)malloc(sizeof(Stack));
	StackInit(s);
	StackPush(s, 1);
	StackPush(s, 2);
	StackPush(s, 3);
	StackPush(s, 4);
	StackPush(s, 5);
	while (StackEmpty(s) != 0)
	{
		printf("%d ", StackTop(s));
		StackPop(s);
	}
	printf("\n");
	/*int flag = StackEmpty(s);
	printf("%d\n", flag);*/
}