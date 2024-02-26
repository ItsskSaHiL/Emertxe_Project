#include "main.h"

void push(Stack_t *stk, int data)
{
	++(stk -> top);
	stk -> stack[stk -> top] = data;
}

char pop(Stack_t *stk)
{
	if (stk -> top != -1)
	return stk->stack[(stk -> top)--];
}

int peek(Stack_t *stk)
{
	if (stk -> top != -1)
	{
		return stk -> stack[stk -> top];
	}
	return -1;
}

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
int check_item(Stack_t *stk)
{
	int item;
	item = stk->top;
	if((item-1) != -1)
	{
		if(priority(stk->stack[item]) > priority(stk->stack[item-1]))
		{
			return 1;
		}
		return 0;
	}
	return 1;
}

