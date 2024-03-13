/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
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
	char	*new_str;
	int		i;

	if (!str_add[0])
		return (old_str);
	i = 0;
	if (old_str)
	{
		while (old_str[i])
			i++;
	}
	new_str = (char *)malloc(sizeof(char) * (i + size + 1));
	if (!new_str)
		return (NULL);
	new_str[i + size] = '\0';
	while (size-- > 0)
		new_str[i + size] = str_add[size];
	while (--i >= 0)
		new_str[i] = old_str[i];
	if (old_str)
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
	if (str[i] == '\0')
		return (-1);
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

	pos = 0;
	count = 0;
	new_str = NULL;
    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
    while (1)
    {
		if (buffer[0] == '\0')
			count = read(fd, buffer, 10);
		if (count < 0)
			break;
		pos = ft_strchr_index(buffer, '\n');
        new_str = ft_strnjoin(new_str, buffer, pos);
		ft_memshift(buffer, pos + 1);
        if ((pos < 10 && pos >= 0) || count == 0)
            break ;
    }
    return (new_str);
}
/*
char	*ft_clearbuffer(void *str, int size)
{
	char	*char_str;

	char_str = (char *) str;
	while (size > 0)
		char_str[--size] = (char) '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*new_str;
	static char	buffer[10 + 1];

	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		ft_clearbuffer(buffer, 10 + 1);
		return (NULL);
	}
	new_str = NULL;
	new_str = ft_process_buffer(fd, new_str, buffer);
	return (new_str);
}

char	*ft_process_buffer(int fd, char *new_str, char *buffer)
{
	int	count;
	int	newline_pos;

	count = 1;
	while (count > 0 || buffer[0] != '\0')
	{
		newline_pos = ft_strchr_index(buffer, '\n');
		if (newline_pos >= 0 && buffer[0] != '\0')
		{
			new_str = ft_strnjoin(new_str, buffer, newline_pos);
			buffer = ft_memshift(buffer, newline_pos + 1);
			break ;
		}
		new_str = ft_strnjoin(new_str, buffer, 10);
		buffer = ft_clearbuffer(buffer, 10 + 1);
		count = read (fd, buffer, 10);
	}
	if (count == -1 || (count == 0 && !new_str))
	{
		ft_clearbuffer(buffer, 10 + 1);
		if (new_str)
			free(new_str);
		return (NULL);
	}
	return (new_str);
}*/

/*char	*get_next_line(int fd)
{
    static char	buffer[10 + 1];
    static int	pos;
	static int	count;
    char		*new_str;

	pos = 0;
	count = 0;
	new_str = NULL;
    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
    while (1)
    {
		if (pos == count)
		{
			count = read(fd, buffer, 10);
			pos = 0;
		}
        if (count <= 0)
            break ;//para se pos==count e count vazio
        new_str = ft_strnjoin(new_str, buffer + pos, 1);
        if (buffer[pos++] == '\n' || count == 0)
            break ;
    }
    if (count == -1)
        free(new_str);
    return (new_str);
}*/



/*char	*get_next_line(int fd)
{
    static char	buffer[10 + 1];
    char		*new_str;
    int		bytes_read;
    int		newline_pos;

    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
    new_str = NULL;
    while ((bytes_read = read(fd, buffer, 10)) > 0)
    {
        buffer[bytes_read] = '\0';
        newline_pos = ft_strchr_index(buffer, '\n');
        if (newline_pos >= 0)
        {
            new_str = ft_strnjoin(new_str, buffer, newline_pos + 1);
            memmove(buffer, buffer + newline_pos + 1, 10 - newline_pos);
            break ;
        }
        new_str = ft_strnjoin(new_str, buffer, bytes_read);
    }
    if (bytes_read <= 0 && !new_str)
    {
        if (new_str)
            free(new_str);
        return (NULL);
    }
    return (new_str);
}*/