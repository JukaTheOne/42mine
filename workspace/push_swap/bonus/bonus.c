/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howtobonus.c                                       :+:      :+:    :+:   */
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
	else
		*error = 1;
}

int	main(int argc, char **argv)
{
	int		error;
	char	*line;
	t_stack	*s_a;
	t_stack	*s_b;

	error = 0;
	if (argc < 2)
		return (0);
	s_a = NULL;
	s_b = NULL;
	ft_extract_stack(&s_a, argc, argv, &error);
	while (line != NULL && !error)
	{
		line = get_next_line(0);
		if (line)
			execute_command(line, &s_a, &s_b, &error);
		free(line);
		if (line == NULL || error)
			break ;
	}
	if (error || s_b || !ft_issorted(s_a, &error))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
	ft_lstprint(s_a);
	ft_lstprint(s_b);
	ft_lstdel(s_a);
	ft_lstdel(s_b);
	return (0);
}
