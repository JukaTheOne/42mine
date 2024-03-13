/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moves_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:18 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 22:56:18 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->prev)
	{
		first = *stack;
		last = (*stack)->prev;
		*stack = first->next;
		last->next = first;
		first->next = NULL;
	}
	return ;
}

void	ra(t_stack **stack_a, int rep, int print)
{
	while (rep--)
	{
		ft_rotate(stack_a);
		if (print)
			write(1, "ra\n", 3);
	}
	return ;
}

void	rb(t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_rotate(stack_b);
		if (print)
			write(1, "rb\n", 3);
	}
	return ;
}

void	rr(t_stack **stack_a, t_stack **stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		if (print)
			write(1, "rr\n", 3);
	}
	return ;
}
