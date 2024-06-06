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
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

void current_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
        if (!tree)
                return;
        if (level == 1)
                func(tree->n);
        else if (level > 1)
        {
                current_level(tree->left, func, level - 1);
                current_level(tree->right, func, level - 1);
        }
}

/**
 * binary_tree_levelorder - goes through a binary tree in level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
        size_t h_counter;
        size_t height = binary_tree_height(tree);

        for (h_counter = 1; h_counter <= height; h_counter++)
                current_level(tree, func, h_counter);
}
