struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		tree_size(struct s_node *n)
{
	return (n ? 1 + tree_size(n->left) + tree_size(n->right) : 0);
}

int		check_nodes(struct s_node *n, int total, int *ret)
{
	if (n)
	{
		int curr;

		curr = 1 + check_nodes(n->left, total, ret) + check_nodes(n->right, total, ret);
		if (curr == total - curr)
			*ret = 1;
	}
	return (0);
}

int		can_split(struct s_node *n)
{
	int ret;

	ret = 0;
	if (n)
	{
		int total;

		total = tree_size(n);
		check_nodes(n, total, &ret);
	}
	return (ret);
}

