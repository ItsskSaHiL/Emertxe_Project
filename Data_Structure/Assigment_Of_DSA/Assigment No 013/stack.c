#include "main.h"

int priority(char opr)
{
	if(opr == '*' || opr == '/')
	{
		return 3;
	}
	if(opr == '+' || opr == '-')
	{
		return 2;
	}
	return 0;
}

void push(Stack_t *stk, char data)
{
	++(stk -> top);
	stk -> stack[stk -> top] = data;
}

char pop(Stack_t *stk)
{
	char temp;
	if (stk -> top != -1)
	{
		temp = stk->stack[stk->top];
		--(stk->top);
		return temp;
	}
	return 0;
}

int peek(Stack_t *stk)
{
	if (stk -> top != -1)
	{
		return stk -> stack[stk -> top];
	}
	return -1;
}
