/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:39:12 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 16:39:12 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	free_tree(binary_tree);
	return ;
}

void	execute_command(char *call, t_stack **s_a, t_stack **s_b, int *error)
{
	if (call && ft_strcmp(call, "sa") == 0)
		sa(s_a, 1, 0);
	else if (call && ft_strcmp(call, "sb") == 0)
		sb(s_b, 1, 0);
	else if (call && ft_strcmp(call, "ss") == 0)
		ss(s_a, s_b, 1, 0);
	else if (call && ft_strcmp(call, "pa") == 0)
		pa(s_a, s_b, 1, 0);
	else if (call && ft_strcmp(call, "pb") == 0)
		pb(s_a, s_b, 1, 0);
	else if (call && ft_strcmp(call, "ra") == 0)
		ra(s_a, 1, 0);
	else if (call && ft_strcmp(call, "rb") == 0)
		rb(s_b, 1, 0);
	else if (call && ft_strcmp(call, "rr") == 0)
		rr(s_a, s_b, 1, 0);
	else if (call && ft_strcmp(call, "rra") == 0)
		rra(s_a, 1, 0);
	else if (call && ft_strcmp(call, "rrb") == 0)
		rrb(s_b, 1, 0);
	else if (call && ft_strcmp(call, "rrr") == 0)
		rrr(s_a, s_b, 1, 0);
	else if (call)
		*error = 1;
}

int	main(int argc, char **argv)
{
	int		error;
	char	*line;
	t_stack	*s_a;
	t_stack	*s_b;

	s_a = NULL;
	s_b = NULL;
	error = 0;
	ft_extract_stack(&s_a, argc, argv, &error);
	if (error)
		return (ft_lstdel(s_a), write (1, "Error\n", 6));
	while (!error)
	{
		line = get_next_line(0);
		execute_command(line, &s_a, &s_b, &error);
		free(line);
		if (line == NULL || error)
			break ;
	}
	if (error || s_b || !ft_issorted(s_a, &error))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_lstdel(s_a);
	ft_lstdel(s_b);
	return (0);
}
