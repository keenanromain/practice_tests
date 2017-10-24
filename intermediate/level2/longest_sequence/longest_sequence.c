struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		longest_sequence(struct s_node *node)
{
	if (node)
	{
		int ldepth;
		int rdepth;

		ldepth = longest_sequence(node->left);
		rdepth = longest_sequence(node->right);
		return (ldepth > rdepth ? ldepth + 1 : rdepth + 1);
	}
	return (0);
}
