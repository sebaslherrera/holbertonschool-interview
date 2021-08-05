#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root of a binary tree.
 *
 * Return: size of a binary tree
 */
size_t binary_tree_size(const heap_t *tree)
{
	size_t size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);
	return (size_left + size_right + 1);
}

/**
 * ith_node - Given a root and a position in the complete
 * binary tree return the selected node
 * Algorithm from stackoverflow to find ith_node
 * @root: Pointer to the root of a binary tree.
 * @i: I-th position in the complete binary tree.
 *
 * Return: Pointer to the node of the binary tree
 */
heap_t *ith_node(heap_t *root, const size_t i)
{
	size_t b = i;

	/* Sanity check: If no tree, always return NULL. */
	if (!root || i < 1)
		return (NULL);

	/* If i is 1, we return the root. */
	if (i == 1)
		return (root);

	/* Set b to the value of the most significant binary digit set in b. */
	while (b & (b - 1))
		b &= b - 1;

	/* We ignore that highest binary digit. */
	b >>= 1;

	/* Walk down the tree as directed by b. */
	while (b)
	{
		if (i & b)
		{
			if (root->right)
				root = root->right;
			else
				return (NULL); /* Not a complete tree, or outside the tree. */
		}
		else
		{
			if (root->left)
				root = root->left;
			else
				return (NULL); /* Not a complete tree, or outside the tree. */
		}

		/* Next step. */
		b >>= 1;
	}
	return (root);
}

/**
 * max_heapify - Order a complete binary tree to max heap
 * @last_node: Pointer o a pointer to the last node of a binary tree.
 *
 * Return: Pointer to last node of a max heap
 */
heap_t *max_heapify(heap_t **last_node)
{
	heap_t *last;
	int temp_n;

	last = *last_node;

	while (last->parent)
	{
		/* Edge case in case that is already a max heap */
		if (last->n <= last->parent->n)
			break;

		temp_n = last->n;
		last->n = last->parent->n;
		last->parent->n = temp_n;
		last = last->parent;
	}
	return (last);
}

/**
 * heap_insert - Inserts a value into a Max binary heap
 *
 * @root: Double pointer to the root of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *last_parent = NULL;
	size_t size, pos_last_parent;
	/* Edge case when root is Null */
	if (root == NULL)
		return (NULL);

	/* Parent root not found */
	if (*root == NULL)
	{
		/* Add a new parent root */
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (*root);
	}
	/* Parent root found  */
	size = binary_tree_size(*root);
	if (size % 2 == 0)
		pos_last_parent = size / 2;
	else
		pos_last_parent = (size + 1) / 2;

	last_parent = ith_node(*root, pos_last_parent);
	new_node = binary_tree_node(last_parent, value);

	if (last_parent->left == NULL)
		last_parent->left = new_node;
	else
		last_parent->right = new_node;
	return (max_heapify(&new_node));
}
