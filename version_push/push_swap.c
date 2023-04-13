#include "push_swap.h"

int size_div(int a)
{
	if (a > 250)
		return (5);
	else if (a > 100)
		return (4);
	else if (a > 60)
		return (3);
	return (2);
}
int *bigger(t_stack *b)
{
	int i;
	int tmp;
	int j;
	int *array;

	array = malloc(sizeof(int) * (1024));
	i = 0;
	j = 0;
	tmp = 0;
	 

	while (b->top >= i)
	{
		array[i] = b->num[i];
 		i++;
	}
	i = 0;
	while (i <= b->top)
	{
		j = 0;
		while ((j + i) <= b->top)
		{
			if (array[i] <= array[i + j])
			{
				tmp = array[i];
				array[i] = array[j + i];
				array[i + j] = tmp;
			}
			j++;
		}
		// printf("array: %d\n ",array[i]);
		i++;
		
	}

	 
	return (array);
}

static void aux_push(t_stack *a, t_stack *b, int d, int top)
{
	pb(a, b);
	if (b->num[b->top] >= top)
	{
		if (a->num[a->top] > d)
			rr(a, b);
		else
			rb(b);
	}
}

void chunksss(t_stack *a, t_stack *b)
{
	int too;
	int d;
	int top;
	too = a->top / size_div(a->top);
	d = chunks(a, too) - 1;
	top = chunks(a, too / 2);
	while (too)
	{
		if (a->num[a->top] <= d && too--)
			aux_push(a, b, d, top);
		else
			ra(a);
	}
	
}
 
void sorted_tree(t_stack *a)
{
	if(a->num[a->top] > a->num[0] && a->num[a->top] > a->num[a->top - 1])
		ra(a);
	else if(a->num[a->top - 1] > a->num[0] && a->num[a->top - 1] > a->num[a->top])
		rra(a);
	if(a->num[a->top] < a->num[0] && a->num[a->top] > a->num[a->top - 1])
		sa(a);
}

void function(t_stack *a, t_stack *b)
{
	int i;
	int  *sorted;
	i = 0;

	while (a->top >= 3)
	{
		chunksss(a, b);
	}
 	sorted_tree(a);
	// while(a->top >= 0)
	// 	pb(a,b);
	sorted = calloc(1024,1024);
	sorted = bigger(b);
	 
	 
		i = 0;
		int pos = 0;
		// int x = 0;
		int j = b->top;
	 	int t =1;
		int h = 0;
		int sort = 0;
	while (b->top >= 0)
	{
		pos = 0;
		t = 1;
		// if (b->num[i] == sorted[h] && i >= b->top / 2)
		// {
		// 	pos = b->top - i;
		// 	while (pos > 0)
		// 	{	
				if(b->num[a->top] == sorted[h])
				{ 
					pa(a,b);
					if(b->num[a->top] == sorted[h + 1])
						pa(a,b);
					else 
						rb(b);
					h++;
				}
				else if(b->num[a->top] == sorted[h + 1])
					pa(a,b);
				else
					rb(b);
				h++;
		// 		// rb(b);
		// 		pos--;
		// 	}
		// 	// pa(a, b);
		// 	h++;
			 
		// 	j = b->top;
		// 	i = -1;
		// }
		// else if (b->num[i] == sorted[h] && i <= b->top / 2)
		// {
		// 	pos = i + 1;
		// 	while (pos > 0)
		// 	{
		// 		rrb(b);
		// 		pos--;
		// 	} 
		// 	pa(a, b);
		// 	j = b->top;
		// 	i = -1;
		// 	h++;
		// }
		// else if (b->num[j] == sorted[h] && j >= b->top / 2)
		// {

		// 	pos = b->top - j;
		// 	while (pos > 0)
		// 	{
		// 		rb(b);
		// 		pos--;
		// 	} 
		// 	pa(a, b);
		// 	h++;
		// 	j = b->top;
		// 	i = -1;
		// }
		// else if (b->num[j] == sorted[h] && j <= b->top / 2)
		// {
		// 	pos = j + 1;
		// 	while (pos > 0)
		// 	{
		// 		rrb(b);
		// 		pos--;
		// 	}
 		// 	pa(a, b);
		// 	j = b->top;
		// 	i = -1;
		// 	h++;
		// }
		if(a->num[a->top] > a->num[a->top -1])
			sa(a);
 		i++;
		j--;
	}
	free(sorted);
 }

int main(int ac, char **av)
{
	t_stack b, a;
	stack_init(&a);
	stack_init(&b);
	
	if (ac > 1)
	{
		if (ac == 2 && check_is_all_number(av[1]))
			char_to_int(&a, av[1]);
		else if (ac > 2 && check_is_all_number_two(av))
			char_to_int_two(&a, av);
		else
			printf("aError\n");
	}
	else
		printf("bError\n");

 
	function(&a, &b);
	// while(1)
	// 	  push(&a,4) ;
	// while(1);
}