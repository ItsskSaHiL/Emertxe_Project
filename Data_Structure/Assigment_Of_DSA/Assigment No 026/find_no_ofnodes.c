#include "tree.h"

int total_nodes(Tree_t *root)
{
        int left,right;
	if(root == NULL)
	{
		return 0;
	}

       	left = total_nodes(root->left);
	right = total_nodes(root->right);

	return (left+right+1);
	
}
