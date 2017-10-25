struct s_node {
	int value;
	struct s_node *next;
};

int		is_looping(struct s_node *node)
{
	struct s_node *fast;
	struct s_node *slow;

	fast = node;
	slow = node;
	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
