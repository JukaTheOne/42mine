/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:07:38 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 19:13:15 by fandre-b         ###   ########.fr       */
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

long	ft_atoi(char *str, int *error)
{
	int		sign;
	long	nbr;

	*error = 0;
	nbr = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str)
		*error = 1;
	while (*str && *str >= '0' && *str <= '9')
		nbr = nbr * 10 + sign * (*str++ - '0');
	if (*str && (*str < '0' || *str > '9' || nbr > INT_MAX || nbr < INT_MIN))
		*error = 1;
	return (nbr);
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

void	ft_putnbr(int nbr)
{
	char	c;
	int		sign;

	sign = 1;
	if (nbr < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	if (nbr / 10)
		ft_putnbr(sign * (nbr / 10));
	c = '0' + sign * (nbr % 10);
	write(1, &c, 1);
	return ;
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

int	main(int argc, char **argv)
{
	int		error;
	t_stack	*stack_a;

	if(argc < 2)
		return (0);
	stack_a = NULL;
	ft_extract_stack(&stack_a, argc, argv, &error);
	ft_sorter_push3(&stack_a);
	//ft_lstprint(stack_a);
	ft_lstdel(stack_a);
	return (error);
}

//mechanical turk

//quicksort, heapsort, or merge sort

//sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

//best case: O(n log n)
//worst case: O(n^2)
//best neighborhood: O(n)

//falta:
// 1. implementar quicksort, heapsort, or merge sort best neighborhood
// 2. is_sorted
// 3. aplicar rrr ao meu algo
// 4. melhorar movimentos
// 5. implementar checker
// 6. implementar visualizador
// 7. implementar bonus (get_next_line, is_sorted, run movements from get)
// 8. reorganizar codigo
// 9. norminette

//add size
//add bucket nmr
