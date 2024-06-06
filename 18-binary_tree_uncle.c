#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * Return: a pointer to the sibling node
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *father;

	if (!node || !node->parent)
		return (NULL);
	father = node->parent;
	if (father->left && father->left != node)
		return (father->left);
	else if (father->right && father->right != node)
		return (father->right);
	else
		return (NULL);
}

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 * Return: a pointer to the uncle node or NULL if not found
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *father, *uncle;

	if (!node || !node->parent)
		return (NULL);
	father = node->parent;
	uncle = binary_tree_sibling(father);
	return (uncle);
}
