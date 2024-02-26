#include "tree.h"

/* Iteratively */
int search_BST(Tree_t * root, int data)
{
	if(root == NULL)
	{
		return FAILURE;
	}
	Tree_t *temp = root;
	while(temp != NULL)
	{
		if(data < temp->data)
		{
			temp = temp->left;
		}
		else if(data > temp->data)
		{
			temp = temp->right;
		}
		else 
		{
			return SUCCESS;
		}
	}
	return NOELEMENT;
}
