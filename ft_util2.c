/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:19:46 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:31:18 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpxcom1(unsigned int s, long long *size, char *hex, char *p)
{
	int	i;

	i = 0;
	if (s == 0 && size[1] == 0)
		while (size[0]--)
				i += write(1, " ", 1);
	else if (s == 0 && size[1] != 0)
	{
		while (size[0]-- - size[1] > 0)
			i += write(1, " ", 1);
		while (size[1]--)
			i += write(1, "0", 1);
	}
	else
	{
		if (size[1] < ft_strlen(hex))
			size[1] = ft_strlen(hex);
		while (size[0]-- - size[1] - ft_strlen(p) > 0)
			i += write(1, " ", 1);
		i += write(1, p, ft_strlen(p));
		while (size[1]-- - ft_strlen(hex) > 0)
			i += write(1, "0", 1);
		i += write(1, hex, ft_strlen(hex));
	}
	return (i);
}

int	ft_printpxcom2(unsigned int s, long long *size, char *hex, char *p)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		while (size[0]-- - size[1] > 0)
			i += write(1, " ", 1);
		while (size[1]--)
			i += write(1, "0", 1);
	}
	else
	{
		if (size[1] < ft_strlen(hex))
			size[1] = ft_strlen(hex);
		i += write(1, p, ft_strlen(p));
		while (size[1] - ft_strlen(hex) > 0)
		{
			i += write(1, "0", 1);
			size[1]--;
		}
		i += write(1, hex, ft_strlen(hex));
		while (size[0]-- - size[1] - ft_strlen(p) > 0)
			i += write(1, " ", 1);
	}
	return (i);
}

int	ft_printpxcom3(char *flag, long long *size, char *hex, char *p)
{
	int	i;

	i = 0;
	if (size[0] < ft_strlen(hex))
		size[0] = ft_strlen(hex);
	if (flag[2] == '-')
	{
		i += write(1, p, ft_strlen(p)) + write(1, hex, ft_strlen(hex));
		while (size[0]-- - ft_strlen(hex) > 0)
			i += write(1, " ", 1);
	}
	else if (flag[3] == '0')
	{
		i += write(1, p, ft_strlen(p));
		while (size[0]-- - ft_strlen(hex) > 0)
			i += write(1, "0", 1);
		i += write(1, hex, ft_strlen(hex));
	}
	else
	{
		while (size[0]-- - ft_strlen(hex) > 0)
			i += write (1, " ", 1);
		i += write(1, p, ft_strlen(p)) + write(1, hex, ft_strlen(hex));
	}
	return (i);
}
