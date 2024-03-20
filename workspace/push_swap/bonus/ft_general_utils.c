/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:00:10 by fandre-b          #+#    #+#             */
/*   Updated: 2024/03/12 23:00:10 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long	ft_atoi(char *str, int *error)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!*str)
		*error = 1;
	while (*str && *str >= '0' && *str <= '9')
		nbr = nbr * 10 + sign * (*str++ - '0');
	if (*str && (*str < '0' || *str > '9' || nbr > INT_MAX || nbr < INT_MIN))
		*error = 1;
	return (nbr);
}

void	ft_putnbr(int nbr)
{
	char	c;
	int		sign;

	sign = 1;
	if (nbr < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	if (nbr / 10)
		ft_putnbr(sign * (nbr / 10));
	c = '0' + sign * (nbr % 10);
	write(1, &c, 1);
	return ;
}
