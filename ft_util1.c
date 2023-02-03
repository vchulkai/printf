/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:31:33 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:29:14 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_strlen(const char *s)
{
	long long	i;
	char		*tem;

	if (!s || !*s)
		return (0);
	tem = (char *)s;
	i = 0;
	while (*tem)
	{
		i++;
		tem++;
	}
	return (i);
}

char	*ft_base_16(unsigned long s, char *str, long long size1)
{
	int				i;
	unsigned long	j;
	char			*k;

	i = 0;
	j = s;
	while (j > 0)
	{
		j = j >> 4;
		i++;
	}
	if (s == 0)
		i++;
	if (size1 > i)
		i = size1;
	k = malloc(sizeof(char) * (i + 1));
	k[i--] = '\0';
	while (i >= 0)
	{
		j = 0;
		j = s | j;
		s = s >> 4;
		k[i--] = str[j % 16];
	}
	return (k);
}

int	ft_countdigit(long long number)
{
	int	i;

	i = 1;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		i++;
		number /= 10;
	}
	return (i);
}

int	print_digits(long long number)
{
	long long	num;
	char		a;

	num = 0;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		num += print_digits(number / 10);
		number %= 10;
	}
	a = number + '0';
	num += write (1, &a, 1);
	return (num);
}

char	*check_assign_null(char *chnull)
{
	if (!chnull)
		return ("(null)");
	else
		return (chnull);
}
