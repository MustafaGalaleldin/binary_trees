#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: depth
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree)
	{
		while (tree->parent)
		{
			depth++;
			tree = tree->parent;
		}
	}
	return (depth);
}

/**
 * is_perfect - detect nodes with 0 child  or 2 in a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @p: pointer
 * @height: height of the tree
*/
void is_perfect(const binary_tree_t *tree, int *p, size_t *height)
{
	size_t depth;

	if (tree && p)
	{
		depth = binary_tree_depth(tree);
		if (!(tree->left && tree->right))
			if ((*height) != depth)
				*p = 0;
		is_perfect(tree->left, p, height);
		is_perfect(tree->right, p, height);
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if perfect 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int sign = 1;
	size_t height;

	if (tree)
	{
		height = binary_tree_height(tree);
		is_perfect(tree, &sign, &height);
		if (sign)
			return (1);
	}
	return (0);
}
