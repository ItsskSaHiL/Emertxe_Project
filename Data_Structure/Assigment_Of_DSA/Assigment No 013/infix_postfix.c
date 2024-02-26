#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
	int pre = 0,i = 0;
	char item;
	// Scan the expression from left to right 
	while(Infix_exp[i])
	{
		if(Infix_exp[i] > 47 )
		{
			 Postfix_exp[pre++] = Infix_exp[i];
		}
		else
		{
			if(stk->top == -1)
			{
				push(stk,Infix_exp[i]);
			}
			else if(Infix_exp[i] == '(')
			{
				push(stk,Infix_exp[i]);
			}
			else if(Infix_exp[i] == ')')
			{
				while((item = pop(stk)) != '(')
				{
					Postfix_exp[pre++] = item;
				}
			}				
			else if(priority(peek(stk)) >= priority(Infix_exp[i]))
			{
				Postfix_exp[pre++] = pop(stk);
			 	push(stk,Infix_exp[i]);
			}
			else
				 push(stk,Infix_exp[i]);
		}
		i++;
	}
	while(stk->top != -1)
	{
		 Postfix_exp[pre++] = pop(stk);
	}
	 Postfix_exp[pre] = '\0';
	return 1;
	
}
