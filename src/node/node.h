#ifndef NODE_H
#define NODE_H

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

#endif
