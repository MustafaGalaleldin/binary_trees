#include "binary_trees.h"
/**
 * is_full - detect nodes with 0 child  or 2 in a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @p: pointer
*/
void is_full(const binary_tree_t *tree, int *p)
{
	if (tree && p)
	{
		if (!((tree->left && tree->right) ||
				(!tree->left && !tree->right)))
			*p = 0;
		is_full(tree->left, p);
		is_full(tree->right, p);
	}
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if full 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int sign = 1;

	if (tree)
	{
		is_full(tree, &sign);
		if (sign)
			return (1);
	}
	return (0);
}
