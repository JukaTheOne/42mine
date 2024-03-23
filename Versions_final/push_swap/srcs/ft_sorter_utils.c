/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:05:46 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 23:05:46 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack	*lst, int *index)
{
	t_stack	*temp;

	*index = 0;
	if (!lst)
		return (0);
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

int	ft_getstack_index(t_stack *stack_a, int find_val)
{
	int		temp_val;
	int		save_val;
	int		temp_index;
	int		index;
	t_stack	*temp;

	temp = stack_a;
	save_val = 2147483647;
	temp_index = 0;
	index = 0;
	while (temp)
	{
		temp_val = temp->value - find_val;
		if (abs(temp_val) < abs(save_val))
		{
			save_val = temp_val;
			index = temp_index;
		}
		temp_index++;
		temp = temp->next;
	}
	if (save_val < 0)
		return (index + 1);
	return (index);
}
