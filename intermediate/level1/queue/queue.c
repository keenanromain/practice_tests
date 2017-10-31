#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void)
{
	struct s_queue *queue;
	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *tmp;

	tmp = (struct s_node *)malloc(sizeof(struct s_node));
	tmp->content = content;
	tmp->next = NULL;
	if (queue->last)
		queue->last->next = tmp;
	else
		queue->first = tmp;
	queue->last = tmp;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;
	void			*content;
	
	if (!queue || !queue->first)
		return (NULL);
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	content = tmp->content;
	free(tmp);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (queue && queue->first)
		return (queue->first->content);
	return (NULL);
}

int isEmpty(struct s_queue *queue)
{
	return ((queue && queue->first) ? 0 : 1);
}
