/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:08:55 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/03 11:08:55 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// queremos criar um checker que leia as instruções e execute elas no stack a e no stack b
// so pode receber um comando por linha
// se a sequencia de comandos terminar com sucesso, ele deve imprimir OK
// se nao, KO
// se houver erro de sintaxe, ERROR
// se houver erro de execucao, ERROR

#include "push_swap.h"

typedef struct s_gnl
{
	char	buffer[10 + 1];
	int		pos;
	int		count;
	int		fd;
	struct s_gnl *next;
}			t_gnl;

t_gnl	*get_fd_node(t_gnl *node, int fd)
{
	int	i;

	i = 0;
	while(node)
	{
		if(node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_gnl *) malloc(sizeof(t_gnl));
	node->fd = fd;
	while (i < 11)
		node->buffer[i] = 0;
	node->pos = 0;
	node->count = 0;
	node->next = NULL;
	return (node);
}

char	*get_next_line_node(int fd)
{
	static t_gnl	*head_node;
	t_gnl			*fd_node;
	int				newl_pos;
	char			*new_str;

    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
	fd_node = get_fd_node(head_node, fd);
	while(1)
	{
		if	(fd_node->pos == fd_node->count);
		{
			fd_node->count = read(fd, fd_node->buffer, 10);
			fd_node-> pos = 0;
			if (fd_node->count <= 0)
				break;
		}
		newl_pos = ft_strchr_index(fd_node->buffer, '\n');
		ft_strnjoin(&new_str,fd_node->buffer + pos, count - newl_pos);
		if(newl_pos > 0)
			break;
	}
	if (fd_node->count == -1 || (fd_node->count == 0 && !new_str))
    {
        free(new_str);
        return (NULL);
    }
    return (new_str);
}


char	*ft_process_buffer(int fd, char *new_str, char *buffer)
{
	static int	count;
	static int	newl_pos;

	count = 1
    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
	while(1)
	{
		if (buffer[0] == '\0')
			count = read(fd, buffer, 10);
		if (count <= 0)
			break;
		newl_pos = ft_strchr_index(buffer, '\n');
		ft_strnjoin(&new_str,buffer, newl_pos);
		ft_memshift(buffer, newl_pos + 1);
		if (newl_pos < 10)
			break;
	}
	if (count == -1 || (count == 0 && !new_str))
    {
        free(new_str);
        return (NULL);
    }
    return (new_str);
}

char	*get_next_line_node2(int fd)
{
	static t_gnl	*head_node;
	t_gnl			*fd_node;
	int				newl_pos;
	char			*new_str;

    if (fd < 0 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return (NULL);
	while(fd_node)
	{
		if(fd_node->fd == fd)
			return (node);
		fd_node = fd_node->next;
	}
	if(!fd_node)
	fd_node = get_fd_node(head_node, fd);
	while(1)
	{
		if	(fd_node->buffer[0] = 0);
			fd_node->count = read(fd, fd_node->buffer, 10);
		if (fd_node->count <= 0)
			break;
		newl_pos = ft_strchr_index(fd_node->buffer, '\n');
		ft_strnjoin(&new_str,fd_node->buffer, newl_pos);
		ft_memshift(fd_node->buffer, newl_pos + 1);
		if (newl_pos = -1 || newl_pos < 10)
			break;
	}
	if (fd_node->count == -1 || (fd_node->count == 0 && !new_str))
    {
        free(new_str);
        return (NULL);
    }
    return (new_str);
}



	//Verifica se existe algo no buffer
	//basta count == pos if !pos
}


int main(void)
{
	fd = open("filename")
	ft_gnl(fd);
	fd = 0; (terminal);
	while ()
}