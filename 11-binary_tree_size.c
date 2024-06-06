#include "binary_trees.h"
/**
 * binary_tree_preorders - goes through a binary tree using pre-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @p: a pointer
*/
void binary_tree_preorders(const binary_tree_t *tree, size_t *p)
{
	if (tree && p)
	{
		(*p)++;
		binary_tree_preorders(tree->left, p);
		binary_tree_preorders(tree->right, p);
	}
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t nodes_number = 0;

	if (tree)
		binary_tree_preorders(tree, &nodes_number);
	return (nodes_number);
}
