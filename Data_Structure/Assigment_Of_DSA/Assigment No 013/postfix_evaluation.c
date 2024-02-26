#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
	int i = 0;
	char result;
	while(Postfix_exp[i])
	{
		if(Postfix_exp[i] > 47)
		{
			push(stk,Postfix_exp[i]);
		}
		else
		{
			int operand2 = pop(stk) - '0';
			int operand1 = pop(stk) - '0';

			switch(Postfix_exp[i])
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
	return i;
}
