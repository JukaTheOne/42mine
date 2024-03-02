/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:04:28 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/29 15:04:28 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack	*lst)
{
	t_stack	*tmp;
	int		is_sorted;
	int		tmp_val;

	tmp = lst;
	tmp_val = -2147483648;
	is_sorted = 1;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->value < tmp_val)
			is_sorted = 0;
		tmp_val = tmp->value;
		tmp = tmp->next;
	}
	return (is_sorted);
}

int	ft_getstack_index_lower(t_stack *stack_a, int stack_b_value)
{
	int		tmp_val;
	int		stack_a_index;
	int		index;
	t_stack	*tmp_a;

	tmp_val = -2147483647;
	stack_a_index = 0;
	index = 0;
	tmp_a = stack_a;
	while (tmp_a)
	{
		if (tmp_a->value < stack_b_value && tmp_a->value > tmp_val)
		{
			tmp_val = tmp_a->value;
			stack_a_index = index;
		}
		index++;
		tmp_a = tmp_a->next;
	}
	return (stack_a_index +1);
}

int	ft_getstack_index(t_stack *stack_a, int stack_b_value)
{
	int		tmp_val;
	int		stack_a_index;
	int		index;
	t_stack	*tmp_a;

	tmp_val = 2147483647;
	stack_a_index = 0;
	index = 0;
	tmp_a = stack_a;
	while (tmp_a)
	{
		if (tmp_a->value > stack_b_value && tmp_a->value < tmp_val)
		{
			tmp_val = tmp_a->value;
			stack_a_index = index;
		}
		index++;
		tmp_a = tmp_a->next;
	}
	if (tmp_val == 2147483647)
		stack_a_index = ft_getstack_index_lower(stack_a, stack_b_value);
	return (stack_a_index);
}
