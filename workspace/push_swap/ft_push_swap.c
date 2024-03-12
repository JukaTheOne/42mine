/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:09:14 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 23:09:14 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tree(t_stack *node)
{
	if (!node)
		return ;
	free_tree(node->prev);
	free_tree(node->next);
	free(node);
	node = NULL;
	return ;
}

void	ft_checkrepeated(t_stack **binary_tree, t_stack *node, int *error)
{
	t_stack	*temp;

	temp = *binary_tree;
	if (!temp)
		*binary_tree = node;
	while (temp && node->value != temp->value && temp != node)
	{
		if (node->value > temp->value)
		{
			if (!temp->next)
				temp->next = node;
			temp = temp->next;
		}
		else if (node->value < temp->value)
		{
			if (!temp->prev)
				temp->prev = node;
			temp = temp->prev;
		}
	}
	if (temp && node->value == temp->value && temp != node)
		*error = 1;
	if (temp && (node->value == temp->value && temp != node))
		free(node);
	return ;
}

void	ft_extract_stack(t_stack **stack, int argc, char **argv, int *error)
{
	int		i;
	int		nbr;
	t_stack	*node;
	t_stack	*node_tree;
	t_stack	*binary_tree;

	i = 1;
	binary_tree = NULL;
	while (i < argc && !*error)
	{
		nbr = ft_atoi(argv[i++], error);
		node = ft_lstnew(nbr);
		node_tree = ft_lstnew(nbr);
		ft_checkrepeated(&binary_tree, node_tree, error);
		ft_lstadd_back(stack, node);
	}
	if (*error)
	{
		ft_lstdel(*stack);
		write (1, "ERROR\n", 6);
	}
	free_tree(binary_tree);
	return ;
}

int	main(int argc, char **argv)
{
	int		error;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	ft_extract_stack(&stack_a, argc, argv, &error);
	ft_sorter_push3(&stack_a);
	ft_lstdel(stack_a);
	return (error);
}
