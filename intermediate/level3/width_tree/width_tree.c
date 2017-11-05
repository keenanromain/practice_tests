struct	s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		height_tree(struct s_node *n)
{
	if (n)
		return (1 + max(height_tree(n->left), height_tree(n->right)));
	return (0);
}

int		width_tree(struct s_node *n)
{
	if (n)
	{
		int l_height;
		int r_height;
		int total_height;
		int l_width;
		int r_width;
		int total_width;

		l_height = height_tree(n->left);
		r_height = height_tree(n->right);
		l_width = width_tree(n->left);
		r_width = width_tree(n->right);
		total_height = 1 + l_height + r_height;
		total_width = max(l_width, r_width);
		return (max(total_height, total_width));
	}
	return (0);
}
