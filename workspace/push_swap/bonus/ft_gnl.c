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

char	*ft_strnjoin(char *old_str, char *str_add, int size)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	while (old_str && old_str[len])
		len++;
	i = 0;
	while (str_add && str_add[i])
		i++;
	if (i < size)
		size = i;
	new_str = (char *) malloc (size + len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (old_str && ++i < len)
		new_str[i] = old_str[i];
	i = -1;
	while (str_add && ++i < size)
		new_str[len + i] = str_add[i];
	new_str[len + i] = '\0';
	free(old_str);
	return (new_str);
}

int	ft_strchr_index(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

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
		new_str = ft_strnjoin(new_str, buffer, pos);
		ft_memshift(buffer, pos + 1);
		if (((pos < 10 && pos >= 0) && buffer[0] != '\0') || count == 0)
			break ;
	}
	if (count == -1 || (count == 0 && (!new_str || !new_str[0])))
		return (free(new_str), NULL);
	return (new_str);
}
