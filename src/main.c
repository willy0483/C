#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
};

struct Node* create_node(int value);
struct Node* insert_node(struct Node* node, int value);
struct Node* search_node(struct Node* node, int value);

void free_node(struct Node* node);

int main()
{
	struct Node* root = NULL;

	int node_arr[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	root = insert_node(root, 10);
	for(int i = 0; i < (sizeof(node_arr) / sizeof(int)); i++)
	{
		insert_node(root, node_arr[i]);
	}

	search_node(root, 18);
	search_node(root, 1);
	search_node(root, 9);

	free_node(root);
	return 0;
}

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
	if(node == NULL || node->key == target)
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
