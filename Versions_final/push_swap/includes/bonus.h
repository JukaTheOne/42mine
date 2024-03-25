/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:40:00 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 23:40:00 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				target;
	int				rot[2];
}					t_stack;

char	**ft_split(int *size, char *str, char c);
//general utils
long	ft_atoi(char *str, int *error);
void	ft_putnbr(int nbr);
int		ft_strcmp(const char *s1, const char *s2);
//gnl
char	*ft_strnjoin(char *old_str, char *str_add, int size);
int		ft_strchr_index(char *str, char c);
char	*ft_memshift(void *str, int n_shift);
char	*get_next_line(int fd);
//char	*ft_clearbuffer(void *str, int size);
//char	*ft_process_buffer(int fd, char *new_str, char *buffer);
//main
void	free_tree(t_stack *node);
void	ft_checkrepeated(t_stack **binary_tree, t_stack *node, int *error);
void	ft_extract_stack(t_stack **stack_a, int argc, char **argv, int *error);
void	execute_command(char *call, t_stack **s_a, t_stack **s_b, int *error);
//list manipulation utils
//genral list utils
t_stack	*ft_lstnew(int nbr);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdel(t_stack *lst);
int		ft_issorted(t_stack	*lst, int *index);
void	ft_lstprint(t_stack *lst);
//list movements
//swap first two elements
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a, int rep, int print);
void	sb(t_stack **stack_b, int rep, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//push top stack
void	ft_push(t_stack **lst, t_stack *new);
void	ft_push_top(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **stack_a, t_stack **stack_b, int rep, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//rotate
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a, int rep, int print);
void	rb(t_stack **stack_b, int rep, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int rep, int print);
//reverse rotate
void	ft_rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a, int rep, int print);
void	rrb(t_stack **stack_b, int rep, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int rep, int print);

#endif
