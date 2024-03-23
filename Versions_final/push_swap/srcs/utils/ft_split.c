/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:12:00 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/23 12:53:35 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countword(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

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

char	**ft_getsplitted(char **matrix, char *str, char c, int size)
{
	int		i;
	int		i_words;

	i_words = 0;
	while (*str && i_words < size)
	{
		i = ft_strchr_index(str, c);
		if (i > 0)
		{
			matrix[i_words] = ft_strnjoin(NULL, str, i);
			if (!matrix[i_words])
			{
				while (i_words-- >= 0)
					free(matrix[i_words]);
				free(matrix);
				return (NULL);
			}
			i_words++;
		}
		str = str + i + 1;
	}
	matrix[i_words] = NULL;
	return (matrix);
}

char	**ft_split(int *size, char *str, char c)
{
	char	**matrix;

	if (!str)
		return (NULL);
	*size = ft_countword(str, c);
	matrix = (char **) malloc (sizeof(char *) * (*size + 1));
	if (!matrix)
		return (NULL);
	matrix = ft_getsplitted(matrix, str, c, *size);
	return (matrix);
}
