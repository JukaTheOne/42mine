/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moves_revrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:56:27 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 22:56:27 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->prev)
	{
		first = *stack;
		last = (*stack)->prev;
		*stack = last;
		last->prev->next = last->next;
		last->next = first;
	}
	return ;
}

void	rra(t_stack **stack_a, int rep, int print)
{
	while (rep--)
	{
		ft_rev_rotate(stack_a);
		if (print)
			write(1, "rra\n", 4);
	}
	return ;
}

void	rrb(t_stack	**stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_rev_rotate(stack_b);
		if (print)
			write(1, "rrb\n", 4);
	}
	return ;
}

void	rrr(t_stack	**stack_a, t_stack	**stack_b, int rep, int print)
{
	while (rep--)
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
		if (print)
			write(1, "rrr\n", 4);
	}
	return ;
}
