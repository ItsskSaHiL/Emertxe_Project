#include "tree.h"

Tree_t *findmin(Tree_t * root)
{
	Tree_t *temp = root;
	while(temp && temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

