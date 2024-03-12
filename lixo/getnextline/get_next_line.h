/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:14 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/20 15:12:38 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_process_buffer(int fd, char *new_str, char *buffer);
char	*ft_strnjoin(char *old_str, char *str_add, int size);
int		ft_strchr_index(char *str, char c);
char	*ft_clearbuffer(void *str, int size);
char	*ft_memshift(void *str, int n_shift);

#endif