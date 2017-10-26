#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack *));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (stack && stack->top)
	{
		struct s_stack *tmp;

		tmp = init();
		tmp->top = stack->top;
		stack->top = stack->top->next;
		return(tmp->top);
	}
	return (NULL);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *newTop;

	newTop = (struct s_node *)malloc(sizeof(struct s_node *));
	newTop->content = content;
	newTop->next = stack->top;
	stack->top = newTop;
}

void *peek(struct s_stack *stack)
{
	if (stack && stack->top)
		return(stack->top);
	return (NULL);
}

int isEmpty(struct s_stack *stack)
{
	return (stack && stack->top ? 0 : 1);
}
