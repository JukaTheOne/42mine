/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:06:36 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/16 21:06:36 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				target;
	int				rot[2];
}					t_stack;

//general utils
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
long	ft_atoi(char *str, int *error);
void	ft_putnbr(int nbr);
//list manipulation utils
t_stack	*ft_lstnew(int nbr);
void	ft_push(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdel(t_stack *lst);
int		ft_getstack_size(t_stack *stack);
//genral list utils
void	ft_lstprint(t_stack *lst);
//main functions
void	free_tree(t_stack *node);
void	ft_checkrepeated(t_stack **binary_tree, t_stack *node, int *error);
void	ft_extract_stack(t_stack **stack_a, int argc, char **argv, int *error);
//list movements
//swap first two elements
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a, int rep, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//push top stack
void	ft_push_top(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **stack_a, t_stack **stack_b, int rep, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//rotate
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a, int rep, int print);
void	rb(t_stack **stack_b, int rep, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//reverse rotate
void	ft_rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a, int rep, int print);
void	rrb(t_stack **stack_b, int rep, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//sorter utils
int		ft_issorted(t_stack	*lst, int *index);
int		ft_getstack_index(t_stack *stack_a, int stack_b_value);
//sorter
void	ft_sort3(t_stack **stack_a);
void	ft_getstack_info(t_stack **stack_a, t_stack **stack_b, int size, int i);
void	ft_getnode_cheapest(t_stack *stack, int **rotator);
void	ft_push_prep(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	ft_sorter_push3(t_stack **stack_a);

#endif