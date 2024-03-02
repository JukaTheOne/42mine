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

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
} 					t_stack;

void	ft_swap(t_stack **stack);
void    sa(t_stack **stack_a);
void    ss(t_stack **stack_a, t_stack **stack_b);
void	ft_push_top(t_stack **stack_from, t_stack **stack_to);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_lstnew(int nbr);
void	ft_push(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdel(t_stack *lst);
long	ft_atoi(char *str, int *error);
void	ft_checkrepeated(t_stack **binary_tree, t_stack *node, int *error);
t_stack *ft_extract_stack(int argc, char **argv, int *error);
void	ft_putnbr(int nbr);
void	ft_lstprint(t_stack *lst);
//int	push_swap(int argc, char **argv);

void    in_order_traversal(t_stack **stack_a, t_stack **stack_b, t_stack *binary_tree);
void    ft_sorter(t_stack **stack_a, t_stack *binary_tree);

#endif