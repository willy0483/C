#include "node/node.h"

int main()
{
	struct Node* root = NULL;

	int node_arr[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	root = insert_node(root, 10);
	for(int i = 0; i < (sizeof(node_arr) / sizeof(int)); i++)
	{
		insert_node(root, node_arr[i]);
	}

	free_node(root);
	return 0;
}
