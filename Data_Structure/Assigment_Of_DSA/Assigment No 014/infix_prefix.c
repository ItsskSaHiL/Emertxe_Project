#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
	int pre = 0,i = 0;
	char item;
	// Scan the expression from left to right 
	while(Infix_exp[i])
	{
		if(Infix_exp[i] > 47 )
		{
			 Prefix_exp[pre++] = Infix_exp[i];
		}
		else
		{
			if(stk->top == -1)
			{
				push(stk,Infix_exp[i]);
			}
			else if(Infix_exp[i] == ')')
			{
				push(stk,Infix_exp[i]);
			}
			else if(Infix_exp[i] == '(')
			{
				while((item = pop(stk)) != ')')
				{
					Prefix_exp[pre++] = item;
				}
			}				
			else if(priority(peek(stk)) > priority(Infix_exp[i]))
			{
				Prefix_exp[pre++] = pop(stk);
			   	// for checking item(top) > item(top-1)
				while(check_item(stk))
				{
					item = pop(stk);
					if(item != ')' && item != '(')
					{
						Prefix_exp[pre++] = item;
					}
				}
			
			 	push(stk,Infix_exp[i]);
			}
			else
				 push(stk,Infix_exp[i]);
		}
		i++;
	}
	while(stk->top != -1)
	{
		 Prefix_exp[pre++] = pop(stk);
	}
	 Prefix_exp[pre] = '\0';
	return 1;
	
}
