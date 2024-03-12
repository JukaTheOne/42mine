/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moves_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:34 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 22:56:34 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (*lst)
	{
		first = *lst;
		*lst = new;
		(*lst)->next = first;
		if (first->prev)
			(*lst)->prev = first->prev;
		else
			(*lst)->prev = first;
		first->prev = new;
	}
	else
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
	}
	return ;
}

void	ft_push_top(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*first;

	if (*stack_from)
	{
		first = *stack_from;
		if (first->next)
		{
			*stack_from = first->next;
			if (first->prev && first->prev != first->next)
				(*stack_from)->prev = first->prev;
			else
				(*stack_from)->prev = NULL;
		}
		else
			*stack_from = NULL;
		ft_push(stack_to, first);
	}
	return ;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_push_top(stack_b, stack_a);
		if (print)
			write(1, "pa\n", 3);
	}
	return ;
}

void	pb(t_stack **stack_a, t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_push_top(stack_a, stack_b);
		if (print)
			write(1, "pb\n", 3);
	}
	return ;
}
