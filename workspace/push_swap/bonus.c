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

#include "push_swap.h"

/*
o codigo em geral está feito.
falta reorganizar as funções 
*/

void    execute_command(char *call, t_stack **s_a, t_stack **s_b, int *error)
{
    error = 0;
    if (strcmp(call, "sa"))
        sa(s_a, 1, 1);
    else if (strcmp(call, "sb"))
        sb(s_b, 1, 1);
    else if (strcmp(call, "ss"))
        ss(s_a, s_b, 1, 1);
    else if (strcmp(call, "pa"))
        pa(s_a, s_b, 1, 1);
    else if (strcmp(call, "pb"))
        pb(s_a, s_b, 1, 1);
    else if (strcmp(call, "ra"))
        ra(s_a, 1, 1);
    else if (strcmp(call, "rb"))
        rb(s_b, 1, 1);
    else if (strcmp(call, "rr"))
        rr(s_a, s_b, 1, 1);
    else if (strcmp(call, "rra"))
        rra(s_a, 1, 1);
    else if (strcmp(call, "rrb"))
        rrb(s_b, 1, 1);
    else if (strcmp(call, "rrr"))
        rrr(s_a, s_b, 1, 1);
    else
        error = 1;
}

int main(int argc, char **argv)
{
    char *line;
    int error;
    t_stack *s_a;
    t_stack *s_b;

    if(argc < 2)
		return (0);
	s_a = NULL;
    s_b = NULL;
	ft_extract_stack(&s_a, argc, argv, &error);
    while (!error)
    {
        line = get_next_line(0);
        execute_command(line, &s_a, &s_b, &error);
        free(line);
        if (line == NULL || error)
            break;
    }
	if (!ft_issorted(s_a, &error) || s_b || error) 
        write (1, "KO\n", 3);
    else
        write (1, "OK\n", 3);
    return (error);
}
