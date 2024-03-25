/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:10:12 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 16:10:12 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	*ft_memshift(void *str, int n_shift)
{
	int		i;
	char	*shifted_str;

	i = 0;
	if (n_shift == 0)
		return (str);
	shifted_str = (char *) str;
	while (shifted_str[i + n_shift])
	{
		shifted_str[i] = shifted_str[n_shift + i];
		i++;
	}
	while (i != (10 + 1))
		shifted_str[i++] = '\0';
	return (shifted_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[10 + 1];
	static int	count;
	int			pos;
	char		*new_str;

	new_str = NULL;
	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
			count = read(fd, buffer, 10);
		if (count < 0)
			break ;
		pos = ft_strchr_index(buffer, '\n');
		new_str = ft_strnjoin(new_str, buffer, ++pos);
		ft_memshift(buffer, pos);
		pos = ft_strchr_index(new_str, '\n');
		if (count == 0 || !new_str || new_str[pos] == '\n')
			break ;
	}
	if (count == -1 || (count == 0 && (!new_str || !new_str[0])))
		return (free(new_str), NULL);
	return (new_str);
}
