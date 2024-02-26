#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
	int flag;
	Tree_t *new = malloc(sizeof(Tree_t));


	if(new == NULL)
	{
		return FAILURE;
	}
	new->left = NULL;
	new->data = data;
	new->right = NULL;
	
	// when only one node is present 
	if(*root == NULL)
	{
		*root = new;
		return SUCCESS;
	}
	
	// when there was many node find the correct position
	Tree_t *temp = *root,*parent;
	while(temp != NULL)
	{
		parent = temp;
		if(data < temp->data)
		{
			temp = temp->left;
			flag = 1;
		}
		else if(data > temp->data)
		{
			 temp = temp->right;
                         flag = 0;
		}
		else
		{
			return DUPLICATE;
		}
	}
	
	// made link
	if(flag)
	{
		parent->left = new;
	}
	else
	{
		parent->right = new;
	}
	return SUCCESS;
}

