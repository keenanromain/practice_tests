#include <stdio.h>

struct	s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void	go_left(struct s_node *node, int print)
{
	if (node)
	{
		if (print || (!node->left && !node->right))
			printf(" %d", node->value);
		go_left(node->left, print);
		go_left(node->right, 0);
	}
}

void	go_right(struct s_node *node, int print)
{
	if (node)
	{
		go_right(node->left, 0);
		go_right(node->right, print);
		if (print || (!node->left && !node->right))
			printf(" %d", node->value);
	}
}

void	perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		go_left(root->left, 1);
		go_right(root->right, 1);
		printf("\n");
	}
}
