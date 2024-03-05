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

queremos criar um checker que leia as instruções e execute elas no stack a e no stack b
so pode receber um comando por linha
se a sequencia de comandos terminar com sucesso, ele deve imprimir OK
se nao, KO
se houver erro de sintaxe, ERROR
se houver erro de execucao, ERROR

#include "get_next_line.h"

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
        if (buffer[pos++] == '\n')
        {
            pos++;
            break ;
        }
    }
    if (count == -1 || (count == 0 && !new_str))
    {
        free(new_str);
        return (NULL);
    }
    return (new_str);
}

int main(void)
{
    char *line;
    while ((line = get_next_line(0)) != NULL)  // 0 is the file descriptor for stdin
    {
        printf("%s\n", line);
        free(line);
    }
    return 0;
}