#include "./includes/push_swap.h"
#include <stdio.h>

bool	is_stack_sorted(t_stack *a)
{
	t_node	*current;

	if (!a->top)
		return (true);
	current = a->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}

void	debug_print_stack(t_stack *s, const char *name)
{
	t_node	*temp;
	int		count = 0;

	printf("%s (size=%d): ", name, s->size);
	temp = s->top;
	while (temp && count < 20)
	{
		printf("[%d|r%d] ", temp->data, temp->rank);
		temp = temp->next;
		count++;
	}
	if (temp)
		printf("...");
	printf("\n");
}

void	verify_ranks(t_stack *a)
{
	t_node	*temp;
	int		*rank_count;
	int		i;
	bool	error = false;

	rank_count = calloc(a->size, sizeof(int));
	if (!rank_count)
		return;

	temp = a->top;
	while (temp)
	{
		if (temp->rank >= 0 && temp->rank < a->size)
			rank_count[temp->rank]++;
		else
		{
			printf("ERROR: Invalid rank %d for element %d\n", temp->rank, temp->data);
			error = true;
		}
		temp = temp->next;
	}

	for (i = 0; i < a->size; i++)
	{
		if (rank_count[i] != 1)
		{
			printf("ERROR: Rank %d appears %d times\n", i, rank_count[i]);
			error = true;
		}
	}

	if (!error)
		printf("✓ Ranks are correctly assigned\n");

	free(rank_count);
}

int	main(int argc, char **argv)
{
	size_t	num_size;
	int		*num_array;
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		if (a) free(a);
		if (b) free(b);
		return (0);
	}
	
	num_size = argc - 1;
	num_array = ft_argv_check(argc, argv);
	if (!num_array)
		return (free(a), free(b), 0);
	
	if (!ft_array_to_stack(a, num_array, num_size))
		return (free(a), free(b), free(num_array), 0);
	
	b->top = NULL;
	b->size = 0;
	
	printf("=== Before sorting ===\n");
	debug_print_stack(a, "Stack A");
	printf("Is sorted: %s\n", is_stack_sorted(a) ? "YES" : "NO");
	
	ft_set_rank(a, num_size, num_array);
	
	printf("\n=== After setting ranks ===\n");
	debug_print_stack(a, "Stack A");
	verify_ranks(a);
	
	printf("\n=== Starting sort ===\n");
	ft_push_swap(a, b, num_size);
	
	printf("\n=== After sorting ===\n");
	debug_print_stack(a, "Stack A");
	debug_print_stack(b, "Stack B");
	printf("Is sorted: %s\n", is_stack_sorted(a) ? "YES" : "NO");
	
	ft_free_stack(a);
	ft_free_stack(b);
	return (free(a), free(b), free(num_array), 0);
}