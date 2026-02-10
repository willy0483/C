#include "node.h"

struct Node* create_node(int value)
{
	struct Node* temp = malloc(sizeof(struct Node));

	temp->key = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct Node* insert_node(struct Node* node, int value)
{
	if(node == NULL)
	{
		node = create_node(value);
		printf("Node: %d - was created\n", value);
	}
	if(value < node->key)
	{
		node->left = insert_node(node->left, value);
	}
	if(value > node->key)
	{
		node->right = insert_node(node->right, value);
	}

	return node;
}

struct Node* search_node(struct Node* node, int target)
{
	if(node->key == target)
	{
		printf("Node was found with value: %d - target: %d\n", node->key, target);
		return node;
	}
	if(node->key < target)
	{
		return search_node(node->right, target);
	}
	return search_node(node->left, target);
}

void free_node(struct Node* node)
{
	if(node == NULL)
	{
		return;
	}
	free_node(node->left);
	free_node(node->right);
	printf("Node: %d - free\n", node->key);
	free(node);
}
