#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}

/**
 * sorted_array_to_avl - take an array to put it in an AVL tree
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1));
}

/**
* build_avl_tree - recursion to build tree
* @array: a pointer to the first element of the array to be converted
* @start: the beginning of the array
* @end: end of the array
* Return: a pointer to the root node
*/
avl_t *build_avl_tree(int *array, int start, int end)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;

	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl_tree(array, start, mid - 1);
	if (root->left != NULL)
		root->left->parent = root;

	root->right = build_avl_tree(array, mid + 1, end);
	if (root->right != NULL)
		root->right->parent = root;

	return (root);
}
