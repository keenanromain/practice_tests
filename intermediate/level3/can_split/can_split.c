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

int		check_nodes(struct s_node *n, int total)
{
	if (n)
	{
		if (tree_size(n) == total - tree_size(n))
			return (1);
		return (check_nodes(n->left, total) || check_nodes(n->right, total));
	}
	return (0);
}

int		can_split(struct s_node *n)
{
	if (n)
	{
		int total = tree_size(n);
		return (check_nodes(n, total));
	}
	return (0);
}
