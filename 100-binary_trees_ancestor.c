#include "binary_trees.h"
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
 * ancestor - helper function
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: ancestor
*/
binary_tree_t *ancestor_func(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *ftemp, *stemp;
	size_t depth_first;
	size_t depth_second;

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);
	if (depth_first == depth_second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		ftemp = first->parent;
		stemp = second->parent;
		while (ftemp && stemp)
		{
			if (ftemp == stemp)
				return (ftemp);
			ftemp = ftemp->parent;
			stemp = stemp->parent;
		}
		return (NULL);
	}
	return (NULL);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return:  a pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *ancestor;
	size_t depth_first;
	size_t depth_second;

	if (!first || !second)
		return (NULL);
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);
	while (depth_first < depth_second)
	{
		second = second->parent;
		depth_second--;
	}
	while (depth_second < depth_first)
	{
		first = first->parent;
		depth_first--;
	}
	ancestor = ancestor_func(first, second);
	return (ancestor);
}
