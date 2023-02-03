/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_con2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:28:34 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:30:59 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpx(unsigned int s, long long *size, char *flag, char *p)
{
	int			i;
	char		*base;
	char		*hex;

	base = "0123456789abcdef";
	if (!p || *p == 'X' || p[1] == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	if (size[1] == 0 && flag[3] == '0')
		size[1] = size[1] - ft_strlen(p);
	hex = ft_base_16((unsigned long)s, base, size[1]);
	if (flag[4] == '.')
	{
		if (flag[2] != '-')
			i += ft_printpxcom1(s, size, hex, p);
		else
			i += ft_printpxcom2(s, size, hex, p);
	}
	else
	{
		i += ft_printpxcom3(flag, size, hex, p);
	}
	free(hex);
	return (i);
}

int	ft_printi(int source, long long *size, char *flag)
{
	int		i;
	int		di;

	i = 0;
	di = ft_countdigit (source);
	if (flag[5] == ' ' && source >= 0)
		i += write(1, " ", 1);
	if (size[1] != 0 && size[1] < di)
		size[1] = di;
	if (flag[2] != '-')
		i += ft_rightint(source, size, flag, di);
	else if (flag[2] == '-')
		i += ft_leftint(source, size, flag, di);
	return (i);
}
/// @brief
/// @param s = source
/// @param si = size
/// @param f = flag
/// @param di = digit
/// @return

int	ft_rightint(long long s, long long *si, char *f, int di)
{
	int	i;

	i = 0;
	if (f[4] == '.')
	{
		if (s == 0 && f[1] != '+')
			i += ft_rightintcom1(s, si, f);
		else if (s > 0 || (f[1] == '+' && s == 0))
			i += ft_rightintcom2(s, si, f, di);
		else if (s < 0)
			i += ft_rightintcom3(s, si, di);
	}
	else if (f[3] == '0')
		i += ft_rightintcom4(s, si, f, di);
	else
		i += ft_rightintcom5(s, si, f, di);
	return (i);
}

int	ft_leftint(long long source, long long *size, char *flag, int di)
{
	int	i;

	i = 0;
	if (flag[1] == '+' && source > 0)
		i += write(1, "+", 1);
	else if (source < 0)
		i += write(1, "-", 1);
	while (size[1]-- > di)
		i += write(1, "0", 1);
	if (size[1] + 1 != 0 || flag[4] != '.' || source != 0)
		i += print_digits(source);
	while (size[0] > i)
		i += write(1, " ", 1);
	return (i);
}
