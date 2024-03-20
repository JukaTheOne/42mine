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
	int		nbr;
	int		n_elem;
	int		i;
	char	**tokens;
	t_stack	*binary_tree;

	binary_tree = NULL;
	while (argc-- > 1 && !*error)
	{
		i = 0;
		tokens = ft_split(&n_elem, *(++argv), 32);
		while (i < n_elem && tokens[i])
		{
			nbr = ft_atoi(tokens[i], error);
			free(tokens[i++]);
			ft_checkrepeated(&binary_tree, ft_lstnew(nbr), error);
			ft_lstadd_back(stack, ft_lstnew(nbr));
		}
		free(tokens);
	}
	if (error)
		ft_lstdel(stack_a);
	free_tree(binary_tree);
	return ;
}

int	main(int argc, char **argv)
{
	int		error;
	t_stack	*stack_a;

	error = 0;
	if (argc < 2)
		return (0);
	stack_a = NULL;
	ft_extract_stack(&stack_a, argc, argv, &error);
	if (error)
		write(1, "Error\n", 6);
	else if (stack_a)
	{
		ft_sorter_push3(&stack_a);
		ft_lstdel(stack_a);
	}
	return (error);
}
