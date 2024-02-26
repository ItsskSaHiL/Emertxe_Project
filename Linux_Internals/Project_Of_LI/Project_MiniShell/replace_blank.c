#include "main.h"

void replace_blank(char *input_string)
{
	int i,j;
    	for(i = 0; input_string[i] != '\0';i++)
    	{
        	if(input_string[i] == ' ')
        	{
            		if(input_string[i + 1] == ' ')
            		{
                		for(j = i + 1; input_string[j] != '\0';j++)
                		{
                    			input_string[j] = input_string[j + 1];
                    			i = 0;
                		}
                
            		}
        	}
        else
        {
            continue;
        }
    }
}
