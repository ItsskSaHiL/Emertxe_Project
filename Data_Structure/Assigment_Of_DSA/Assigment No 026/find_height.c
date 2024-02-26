#include "tree.h"

int find_height(Tree_t *root)
{
	if(root == NULL)
	{
		return 0;
	}
	int right_hight,left_hight;
	left_hight = find_height(root->left);
	right_hight = find_height(root->right);
	if(left_hight > right_hight)
	{
		return left_hight+1;
	}
	else
	{
		 return right_hight+1;
	}
}

