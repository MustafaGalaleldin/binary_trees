#include "binary_trees.h"
/**
 * detect_parent - detect nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to traverse
 * @p: a pointer
*/
void detect_parent(const binary_tree_t *tree, size_t *p)
{
	if (tree && p)
	{
		if (tree->left || tree->right)
			(*p)++;
		detect_parent(tree->left, p);
		detect_parent(tree->right, p);
	}
}
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: nodes number
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_number = 0;

	if (tree)
		detect_parent(tree, &nodes_number);
	return (nodes_number);
}
