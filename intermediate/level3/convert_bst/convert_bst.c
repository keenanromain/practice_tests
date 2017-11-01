 struct s_node {
	int value;
	s_node *left;
	s_node *right;
};

struct  s_node  *join(struct s_node *l_list, struct s_node *r_list)
{
	if (!l_list)
		return (r_list);
	if (!r_list)
		return (l_list);
	struct s_node *l_new = l_list->left;
	struct s_node *r_new = r_list->right;
	l_new->right = r_list;
	r_list->left = l_new;
	l_list->left = r_new;
	r_new->right = l_list;
	return (l_list);
}

struct  s_node  *convert_bst(struct s_node *bst)
{
	if (bst)
	{
		struct s_node *left;
		struct s_node *right;

		left = convert_bst(bst->left);
		right = convert_bst(bst->right);
		bst->left = bst;
		bst->right = bst;
		return (join(join(left, bst), right));
	}
	return (bst);
}
