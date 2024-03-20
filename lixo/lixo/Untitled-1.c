/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:40 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/03 21:35:31 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*get_next_line(int fd)
{
	char		*new_str;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0 || read(fd, 0, 1))
	{
		ft_clearbuffer(buffer, BUFFER_SIZE + 1);
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
			new_str = ft_strnjoin(new_str, buffer, newline_pos + 1);
			buffer = ft_memshift(buffer, newline_pos + 1);
			break ;
		}
		new_str = ft_strnjoin(new_str, buffer, BUFFER_SIZE);
		buffer = ft_clearbuffer(buffer, BUFFER_SIZE + 1);
		count = read (fd, buffer, BUFFER_SIZE);
	}
	if (count == -1 || (count == 0 && !new_str))
	{
		ft_clearbuffer(buffer, BUFFER_SIZE + 1);
		if (new_str)
			free(new_str);
		return (NULL);
	}
	return (new_str);
}*/

/*
char	*get_next_line(int fd)
{
    static char	buffer[BUFFER_SIZE + 1];
    static int	pos = 0;
    static int	count = 0;
    char		*new_str;

    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
    new_str = NULL;
    while (1)
    {
        if (pos == count)
        {
            count = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if (count <= 0)
                break ;
        }
        new_str = ft_strnjoin(new_str, buffer + pos, 1);
        if (buffer[pos] == '\n')
        {
            pos++;
            break ;
        }
        pos++;
    }
    if (count == -1 || (count == 0 && !new_str))
    {
        free(new_str);
        return (NULL);
    }
    return (new_str);
}*/

char	*get_next_line(int fd)
{
    static char	buffer[BUFFER_SIZE + 1];
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
        if (pos == count && (count = read(fd, buffer, BUFFER_SIZE)) <= 0)
            break ;//para se pos==count e count vazio
        new_str = ft_strnjoin(new_str, buffer + pos, 1);
        if (buffer[pos++] == '\n')
            break ;
    }
    if (count == -1 || (count == 0 && !new_str))
        free(new_str);
    return (new_str);
}

/* 
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("Loren.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s\n//////////\n", str);
		if (!str)
			break ;
		else
			free(str);
	}
	return (0);
	close(fd);
	fd = open("Loren.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s\n//////////\n", str);
		if (!str)
			break ;
		else
			free(str);
	}
}*/
