/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:08:40 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/20 15:20:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*new_str;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	new_str = NULL;
	new_str = ft_process_buffer(fd, new_str, buffer[fd]);
	return (new_str);
}

char	*ft_process_buffer(int fd, char *new_str, char *buffer)
{
	int	count;
	int	newline_pos;

	count = 1;
	while (count > 0)
	{
		newline_pos = ft_strchr_index(buffer, '\n');
		if (newline_pos >= 0)
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
		return (NULL);
	}
	return (new_str);
}

/* int	main(void)
{
	int	fd;
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
} */
