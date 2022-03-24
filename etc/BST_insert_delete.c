#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;
node* newNode(int data);
node* insert(node* a, int key);
void print_node(node* a);
node* minValue(node* a);
node* delete(node* a, int key);

void main() {
	node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 60);
	root = insert(root, 70);
	root = insert(root, 30);
	root = insert(root, 40);
	print_node(root);
	printf("\n\n");

	root = delete(root, 30);
	print_node(root);
	printf("\n\n");

	root = delete(root, 50);
	print_node(root);
	printf("\n\n");

	root = delete(root, 70);
	print_node(root);
	printf("\n\n");

	root = delete(root, 10);
	print_node(root);
	printf("\n\n");
}
node* newNode(int data) {
	node* root = malloc(sizeof(node));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}
node* insert(node* a, int key) {
	
	if (a == NULL)
		return newNode(key);

	if (key < a->data)
		a->left = insert(a->left, key);
	else
		a->right = insert(a->right, key);

	return a;
}
void print_node(node* a) {
	if (a != NULL) {
		print_node(a->left);
		printf("%d ", a->data);
		print_node(a->right);
	}
}
node* minValue(node* a) {
	node* b = a;
	while (b && b->left != NULL)
		b = b->left;
	return b;
}
node* delete(node* a, int key) {
	if (a == NULL)
		return a;

	node* b = NULL;

	if (key < a->data)
		a->left = delete(a->left, key);

	else if (key > a->data)
		a->right = delete(a->right, key);
	
	else {

		if (a->left == NULL) {
			b = a->right;
			free(a);
			return b;
		}
		else if (a->right == NULL) {
			b = a->left;
			free(a);
			return b;
		}

		b = minValue(a->right);
		a->data = b->data;
		a->right = delete(a->right, b->data);
	}
	return a;
}