/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:47:30 by fandre-b          #+#    #+#             */
/*   Updated: 2024/02/11 17:47:30 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    in_order_traversal(t_stack **stack_a, t_stack **stack_b, t_stack *binary_tree)
{
    if (!binary_tree || !stack_a)
        return ;
    in_order_traversal(stack_a, stack_b, binary_tree->prev);  // começa pela arvore à direita (biggest value)
    //poderia adicionar aqui uma forma de detectar posicao para rr ou rrr
    //corre ix e dps da rr ou rrr ix ou total-ix
    while(*stack_a && (*stack_a)->value != binary_tree->value)
        ra(stack_a);
    pa(stack_a, stack_b);
    in_order_traversal(stack_a, stack_b, binary_tree->next);  // visita arvore à esquerda
    return ;
}

void    ft_sorter(t_stack **stack_a, t_stack *binary_tree)
{
    t_stack *stack_b;

    stack_b = NULL;
    in_order_traversal(stack_a, &stack_b, binary_tree);
    while (stack_b) 
        pb(stack_a, &stack_b);
    if (stack_b)
        ft_lstdel(stack_b);
    return ;
}