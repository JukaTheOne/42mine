/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:09:00 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/20 15:25:00 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_clearbuffer(void *str, int size)
{
	char	*char_str;

	char_str = (char *) str;
	while (size > 0)
		char_str[--size] = (char) '\0';
	return (str);
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
	while (i != (BUFFER_SIZE + 1))
		shifted_str[i++] = '\0';
	return (shifted_str);
}
