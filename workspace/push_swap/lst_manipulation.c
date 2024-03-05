/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:47:59 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/17 20:47:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Bubble Sort
Selection Sort
Insertion Sort
Shell Sort
Merge Sort
Quick Sort
Heap Sort
Radix Sort
(sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).*/
//sacar 3 4 5 11

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
