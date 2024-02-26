#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
	int i = 0;
	char result;
	while(Prefix_exp[i])
	{
		if(Prefix_exp[i] > 47)
		{
			push(stk,Prefix_exp[i]);
		}
		else
		{
			int operand1 = pop(stk) - '0';
			int operand2 = pop(stk) - '0';

			switch(Prefix_exp[i])
			{
				case '+':
					result = (operand1 + operand2) + '0';
					push(stk,result);
					break;
				case '-':
					result = (operand1 - operand2) + '0';
					push(stk,result);
					break;
				case '*':
					result = (operand1 * operand2) + '0';
					push(stk,result);
					break;
				case '/':
					result = (operand1 / operand2) + '0';
					push(stk,result);
					break;
			}
		}
		i++;
	}
	i = pop(stk) - '0';	
}
