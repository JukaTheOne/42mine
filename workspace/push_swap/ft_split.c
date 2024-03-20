/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:12:00 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/19 20:16:09 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_getnextword(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && c == s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(s);
	dst = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, src_len + 1);
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	new_str = (char *) malloc (sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, &s[start], len + 1);
	return (new_str);
}

static char	**ft_getsplitted(const char *s, char **matrix, char c, size_t size)
{
	size_t	index;
	size_t	k;

	index = 0;
	while (s[index] && c == s[index])
		index++;
	k = 0;
	while (k < size)
	{
		matrix[k] = ft_substr(s, index, ft_wordlen(&s[index], c));
		if (!matrix[k++])
		{
			while (k > 0)
				free(matrix[--k]);
			free(matrix);
			return (NULL);
		}
		index += ft_getnextword(&s[index], c);
	}
	matrix[k] = NULL;
	return (matrix);
}

char	**ft_split(int *size, const char *s, char c)
{
	char	**matrix;

	if (!s)
		return (NULL);
	*size = ft_countword(s, (char) c);
	matrix = (char **) malloc (sizeof(char *) * (*size + 1));
	if (!matrix)
		return (NULL);
	return (ft_getsplitted(s, matrix, (char) c, *size));
}
