struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

// feed find_sequence the actual node, the current length at the time of passing, the increased & expected value, and the result as an integer pointer
void	find_sequence(struct s_node *node, int curr_len, int expected, int *result)
{
	if (node)
	{
		if (expected == node->value) // check to see if the current node's value is the same as the previous node's plus one
			curr_len++; // at the very least, we'll have a sequence with at least one
		else
			curr_len = 0; // if it isn't, we need to reset and try again from scratch
		*result = ft_max(*result, curr_len); // stores the appropriate amount inside the result that will be returned in the actual longest_sequence function
		find_sequence(node->left, curr_len, node->value + 1, result); // recurse left in pursuit of longest consecutive increase in node values
		find_sequence(node->right, curr_len, node->value + 1, result); // recurse right in pursuit of longest consecutive increase in node values
	}
}

int		longest_sequence(struct s_node *node)
{
	int result = 0;

	if (node)
		find_sequence(node, 0, node->value, &result);
	return (result);
}
