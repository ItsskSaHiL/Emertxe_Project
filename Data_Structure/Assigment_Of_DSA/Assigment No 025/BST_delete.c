#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t * delete_BST(Tree_t * root, int data)
{
	// Handle the base condition 
	if(root == NULL)
	{
		return root;
	}
	Tree_t *temp;
	// condition for check the Node 
	if(data < root->data)
	{
		root->left = delete_BST(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = delete_BST(root->right, data);
	}
	else
	{
		if(root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			temp = findmin(root->right);
			root->data = temp->data;
			root->right = delete_BST(root->right,temp->data);
		}
	}
	status = 1;
	return root;
}
