/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moves_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:10 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 22:56:10 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		if (second->next)
			second->next->prev = first;
		second->prev = first->prev;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		*stack = second;
		second = first;
	}
	return ;
}

void	sa(t_stack **stack_a, int rep, int print)
{
	while (rep--)
	{
		ft_swap(stack_a);
		if (print)
			write(1, "sa\n", 3);
	}
	return ;
}

void	sb(t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_swap(stack_b);
		if (print)
			write(1, "sb\n", 3);
	}
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		if (print)
			write(1, "ss\n", 3);
	}
	return ;
}
