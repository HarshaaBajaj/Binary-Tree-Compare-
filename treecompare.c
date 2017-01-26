#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* new_Node(int data)
{
	struct node* node = (struct node*)
							malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

int testing_trees(struct node* a, struct node* b)
{
	if (a==NULL && b==NULL)
		return 1;

	if (a!=NULL && b!=NULL)
	{
		return
		(
			a->data == b->data &&
			testing_trees(a->left, b->left) &&
			testing_trees(a->right, b->right)
		);
	}
	return 0;
} 

main()
{
	struct node *root1 = new_Node(1);
	struct node *root2 = new_Node(1);
	root1->left = new_Node(2);
	root1->right = new_Node(3);
	root1->left->left = new_Node(4);
	root1->left->right = new_Node(5); 

	root2->left = new_Node(2);
	root2->right = new_Node(3);
	root2->left->left = new_Node(4);
	root2->left->right = new_Node(5); 

	if(testing_trees(root1, root2))
		printf("Trees are identical.\n");
	else
		printf("Trees are not identical.\n");

}
