#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *do_work(struct s_node *old)
{
	if (old)
	{
		struct s_node *new;
		new = (struct s_node *)malloc(sizeof(struct s_node));
		new->data = old->data;
		new->next = do_work(old->next);
		return (new);
	}
	return (NULL);
}

struct s_node *clone_list(struct s_node *node)
{
	if (node)
	{
		struct s_node *new = do_work(node);
		struct s_node *old_head;
		struct s_node *new_head;
		struct s_node *i = node;
		struct s_node *j = new;
		int		need_malloc;

		while (i && j)
		{	old_head = node;
			new_head = new;
			if (i->other)
			{
				need_malloc = 1;
				while (old_head && new_head)
				{
					if (i->other == old_head)
					{
						j->other = new_head;
						need_malloc = 0;
					}
					old_head = old_head->next;
					new_head = new_head->next;
				}
				if (need_malloc)
					j->other = do_work(i->other);
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
