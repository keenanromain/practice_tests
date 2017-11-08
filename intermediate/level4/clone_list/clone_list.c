#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *clone_non_other(struct s_node *old)
{
	if (old)
	{
		struct s_node *new;
		new = (struct s_node *)malloc(sizeof(struct s_node));
		new->data = old->data;
		new->next = clone_non_other(old->next);
		return (new);
	}
	return (NULL);
}

struct s_node *clone_list(struct s_node *node)
{
	if (node)
	{
		struct s_node *new = clone_non_other(node);
		struct s_node *old_head;
		struct s_node *new_head;
		struct s_node *i = node;
		struct s_node *j = new;

		while (i && j)
		{
			if (i->other)
			{
				old_head = node;
				new_head = new;
				while (old_head && new_head)
				{
					if (i->other == old_head)
					{
						j->other = new_head;
						break ;
					}
					old_head = old_head->next;
					new_head = new_head->next;
				}
			}
			else
				j->other = NULL;
			i = i->next;
			j = j->next;
		}
		return (new);
	}
	return (NULL);
}
