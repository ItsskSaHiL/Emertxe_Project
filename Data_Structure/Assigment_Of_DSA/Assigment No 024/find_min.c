#include "tree.h"

int findmin(Tree_t * root)
{
	// Handle the base condition 
	if(root == NULL)
	{	
		return FAILURE;
	}
	//we Use recursive call for for find minimum element
	if(root->left == NULL)
	{
		return root->data;
	}
	findmin(root->left);
}

