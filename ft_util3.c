/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:55:17 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:31:31 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rightintcom1(long long s, long long *si, char *f)
{
	int	i;

	i = 0;
	if (s == 0 && f[1] != '+')
	{
		if (si[1] == 0)
		{
			while (si[0]--)
				i += write(1, " ", 1);
		}
		else
		{
			while (si[0]-- - si[1] > 0)
				i += write(1, " ", 1);
			while (si[1]--)
				i += write(1, "0", 1);
		}
	}
	return (i);
}

int	ft_rightintcom2(long long s, long long *si, char *f, int di)
{
	int	i;

	i = 0;
	if (f[1] == '+')
		si[0]--;
	if (si[1] < di)
		si[1] = di;
	while (si[0]-- - si[1] > 0)
		i += write(1, " ", 1);
	if (f[1] == '+')
		i += write(1, "-", 1);
	while (si[1]-- - di > 0)
		i += write(1, "0", 1);
	i += print_digits(s);
	return (i);
}

int	ft_rightintcom3(long long s, long long *si, int di)
{
	int	i;

	i = 0;
	si[0]--;
	if (si[1] < di)
		si[1] = di;
	while (si[0]-- - si[1] > 0)
		i += write(1, " ", 1);
	i += write(1, "-", 1);
	while (si[1]-- - di > 0)
		i += write(1, "0", 1);
	i += print_digits(s);
	return (i);
}

int	ft_rightintcom4(long long s, long long *si, char *f, int di)
{
	int	i;

	i = 0;
	if (s < 0)
	{
		i += write(1, "-", 1);
		si[0]--;
	}
	else if (s > 0 && f[1] == '+')
	{
		i += write(1, "+", 1);
		si[0]--;
	}
	while (si[0]-- - di > 0)
		i += write (1, "0", 1);
	i += print_digits(s);
	return (i);
}

int	ft_rightintcom5(long long s, long long *si, char *f, int di)
{
	int	i;

	i = 0;
	if (s < 0 || f[1] == '+')
		si[0]--;
	while (si[0]-- - di > 0)
		i += write (1, " ", 1);
	if (s < 0)
		i += write(1, "-", 1);
	else if (f[1] == '+')
		i += write(1, "+", 1);
	i += print_digits(s);
	return (i);
}
