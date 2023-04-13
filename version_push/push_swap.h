
#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

#define STACK_SIZE 500
#define SIZE 500

typedef struct s_stack {
	int num[STACK_SIZE];
	int top;
} t_stack;

typedef struct s_vars
{
	int middletop;
	int middle;
	int middlebottom;
} t_vars;

void stack_init(t_stack *stack);
void push(t_stack *stack, int element);
int pop(t_stack *stack);
void swap(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

void char_to_int(t_stack *a, char *av);
void char_to_int_two(t_stack *a, char **av);
int check_is_all_number_two(char **av);
int check_is_all_number(char *av);
int chunks(t_stack *a, int too);

#endif



