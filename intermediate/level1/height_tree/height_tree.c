struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	if (root)
	{
		int max;
		int ret;
		int i;
		struct s_node **arr;

		max = 0;
		ret = -1;
		i = -1;
		if ((arr = root->nodes;))
			while (arr[++i])
				if ((max = height_tree(arr[i])) > ret)
					ret = max;
		return (ret + 1);
	}
	return (-1);
}
