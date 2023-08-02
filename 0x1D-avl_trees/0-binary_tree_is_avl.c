#include "binary_trees.h"

/**
 * binary_height - function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: the height of a binary tree
 */
int binary_height(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (!tree)
		return (0);

	height_left = 1 + binary_height(tree->left);
	height_right = 1 + binary_height(tree->right);

	if (height_left < height_right)
		return (height_right);

	return (height_left);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	left = binary_height(tree->left);
	right = binary_height(tree->right);

	return (left - right);
}

/**
 * is_bst - function that checks if a binary tree is a valid Binary
 * Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value a node on the left side
 * @max: the maximum value of node on the right side
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
	is_bst(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid Binary
 * Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  a pointer to the root node of the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst = binary_tree_is_bst(tree);
	int bf = binary_tree_balance(tree);

	if (!tree)
		return (0);

	if (bst == 1 && (bf == 1 || bf == 0 || bf == -1))
	{
		if (!tree->right && !tree->left)
			return (1);

		else if (tree->left && !tree->right)
			return (binary_tree_is_avl(tree->left));

		else if (tree->right && !tree->left)
			return (binary_tree_is_avl(tree->right));

		else
		{
			return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
		}
	}
	return (0);
}
