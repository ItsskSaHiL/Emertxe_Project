#include "tree.h"

int findmax(Tree_t * root)
{
	// Handle the base case 
	if(root == NULL)
	{
		return FAILURE;
	}
	// Find the maximum recursively 
	if(root->right == NULL)
	{
		return root->data;
	}
	findmax(root->right);
	
}

