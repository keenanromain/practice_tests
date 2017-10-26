struct s_node {
	int           value;
	struct s_node **nodes;
};

int		height_tree(struct s_node *root)
{
	if (root)
	{
		int ret;
		int i;
		int num;
		struct s_node *tmp;
		int h;

		ret = 0;
		i = -1;
		num = 0;
		tmp = root;
		while (tmp)
		{
			tmp = *(tmp->nodes);
			num++;
		}
		tmp = root;
		while (++i <= num)
			if ((h = height_tree(root->nodes[i])) > ret)
				ret = h;
		return (ret + 1);
	}
	return (-1);
}
