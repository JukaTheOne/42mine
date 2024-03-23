/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_general_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:03:42 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 23:03:42 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*current;

	current = (t_stack *) malloc(sizeof(t_stack));
	if (!current)
		return (NULL);
	current->value = nbr;
	current->next = NULL;
	current->prev = NULL;
	return (current);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = (*lst)->prev;
		if (last)
		{
			last->next = new;
			new->prev = last;
			(*lst)->prev = new;
		}
		else
		{
			(*lst)->next = new;
			new->prev = *lst;
			(*lst)->prev = new;
		}
	}
	else
		(*lst) = new;
	return ;
}

void	ft_lstdel(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	return ;
}

int	ft_getstack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!stack)
		return (size);
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	ft_lstprint(t_stack *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putnbr(lst->value);
		write (1, " ", 1);
		lst = lst->next;
	}
	write (1, "\n", 1);
	return ;
}
