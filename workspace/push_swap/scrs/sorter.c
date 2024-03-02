/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:26:00 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/02 10:26:00 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_issorted(t_stack	*lst, int *index)
{
	t_stack	*temp;

	*index = 0;
	temp = lst;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
		(*index)++;
	}
	return (1);
}

int	ft_getstack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_getstack_index_lower(t_stack *stack_a, int find_val)
{
	int		temp_val;
	int		i;
	int		index;
	t_stack	*temp;

	i = 0;
	temp_val = -2147483648;
	temp = stack_a;
	while (temp)
	{
		if (temp->value < find_val && temp->value > temp_val)
		{
			temp_val = temp->value;
			index = i;
		}
		i++;
		temp = temp->next; 
	}
	return (index + 1);
}

int	ft_getstack_index(t_stack *stack_a, int find_val)
{
	int		temp_val;
	int		i;
	int		index;
	t_stack	*temp;

	i = 0;
	temp_val = 2147483647;
	temp = stack_a;
	while (temp)
	{
		if (temp->value > find_val && temp->value < temp_val)
		{
			temp_val = temp->value;
			index = i;
		}
		if (temp_val == 2147483647)
			index = ft_getstack_index_lower(stack_a, temp->value);
		i++;
		temp = temp->next; 
	}
	return (index);
}

void	ft_getstack_info(t_stack **stack_a, t_stack **stack_b, int size, int i)
{
	int		index_a;
	int		index_b;
	t_stack	*temp;

	index_b = 0;
	temp = *stack_b;
	while (temp)
	{
		temp->target = ft_getstack_index(*stack_a, temp->value);
		index_a = temp->target;
		if (index_a <= ((size - 3) - i) / 2)
			temp->rot[0] = index_a;
		else
			temp->rot[0] = -((size - 3) - index_a);
		if (index_b <= i / 2)
			temp->rot[1] = index_b;
		else
			temp->rot[1] = -(i - index_b);
		temp = temp->next; 
		index_b++;
	}
	return ;
}

void	ft_sort3(t_stack **stack_a)
{
	int burn_variable;

	while (!ft_issorted(*stack_a, &burn_variable))
	{
		if ((*stack_a)->value > (*stack_a)->prev->value)
			ra(stack_a, 1, 1);
		if ((*stack_a)->next->value > (*stack_a)->prev->value)
			rra(stack_a, 1, 1);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 1, 1);
	} 
	return ;
	}

void	ft_getnode_cheapest(t_stack *stack, int **rotator)
{
	int		temp_val;
	int		*rot;
	int		total_rot;
	t_stack	*temp;

	total_rot = 2147483647;
	temp = stack;
	while (temp)
	{
		rot = temp->rot;
		if (ft_abs(rot[0] - rot[1])  < ft_abs(rot[0]) + ft_abs(rot[1]))
			temp_val = ft_max(ft_abs(rot[0]),ft_abs(rot[1]));
		else
			temp_val = ft_abs(rot[0]) + ft_abs(rot[1]);
		if (temp_val < total_rot)
		{
			total_rot = temp_val;
			*rotator = rot;
		}
		temp = temp->next; 
	}
	return ;
}

void	ft_push_prep(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	int		rr_mov;
	int		rrr_mov;

	rr_mov = 0;
	rrr_mov = 0;
	if (a > 0 && b > 0)
		rr_mov = ft_min(a,b);
	if (a < 0 && b < 0)
		rrr_mov = ft_max(a,b);
	ra(stack_a, (a - rr_mov), 1);
	rb(stack_b, (b - rr_mov), 1);
	rra(stack_a, -(a - rrr_mov), 1);
	rrb(stack_b, -(b - rrr_mov), 1);
	rr(stack_a, stack_b, rr_mov, 1);
	rrr(stack_a, stack_b, rrr_mov, 1);
	return ;
}

void	ft_sorter_push3(t_stack **stack_a)
{
	int		size;
	int		*rotator;
	int		i;
	t_stack	*stack_b;

	i = 0;
	size = ft_getstack_size(*stack_a);
	stack_b = NULL;
	pb(stack_a, &stack_b, size - 3, 1);
	ft_sort3(stack_a);
	while (stack_b)
	{
		ft_getstack_info(stack_a, &stack_b, size, i);
		ft_getnode_cheapest(*stack_a, &rotator);
		ft_push_prep(stack_a, &stack_b, rotator[0], rotator[1]);
		pa(stack_a, &stack_b, 1, 1);
		i++;
	}
	if (!ft_issorted(*stack_a, &i) && i <= size / 2)
		ra(stack_a, i, 1);
	else
		rra(stack_a, size - i, 1);
	return ;
}
