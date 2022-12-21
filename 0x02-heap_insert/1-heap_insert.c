#include "binary_trees.h"

/**
* swap - function to swap nodes
* @parent: node to swap
* @node: node to swap
*/
void swap(int *parent, int *node)
{
	int tmp;

	tmp = *node;
	*node = *parent;
	*parent = tmp;
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
* find_children - find children location
* @root: the head of the tree
* @idx: the index of the node to check
* @size: the number of nodes in the tree
* Return: left if child on left, right if child on right othrewise Null
*/
heap_t *find_children(heap_t *root, size_t idx, size_t size)
{
	heap_t *left, *right;

	if (idx == size)
		return (root);

	if (idx > size)
		return (NULL);

	left = find_children(root->left, 2 * idx + 1, size);
	right = find_children(root->right, 2 * idx + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);
}

/**
* find_parent - find the parent location in the tree
* @root: the head of the tree
* @new: the node to insert
* Return: the parent location
*/
heap_t *find_parent(heap_t *root, heap_t *new)
{
	heap_t *parent;
	size_t size;

	size = binary_tree_size(root);
	parent = find_children(root, 0, (size - 1) / 2);

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	return (parent);
}

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root:  a double pointer to the root node of the Heap
* @value: the value to store in the node to be inserted
*
* Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);

	if (!root || !(*root))
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_parent(*root, new_node);
	new_node->parent = parent;

	while (new_node->parent && new_node->parent->n < new_node->n)
	{
		swap(&new_node->parent->n, &new_node->n);
		new_node = new_node->parent;
	}

	return (new_node);
}
