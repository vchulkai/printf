/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_con1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:21:28 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:28:21 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s);
// int		ft_countdigit(long long number);
// char	*ft_base_16(unsigned long s, char *str, long long size1);

int	ft_printc(char source, long long *size, char flag)
{
	int	i;

	i = 1;
	if (size[0] < 0)
		size[0] = -size[0];
	if (flag == '-')
	{
		write(1, &source, 1);
		while (size[0] > 0 && size[0] - i > 0)
			i += write(1, " ", 1);
	}
	else
	{
		while (size[0] > 0 && size[0] - i > 0)
			i += write(1, " ", 1);
		write(1, &source, 1);
	}
	return (i);
}

int	ft_prints(char *source, long long *size, char *flag)
{
	int	i;
	int	j;

	if (!source)
		source = check_assign_null(source);
	i = ft_strlen(source);
	j = 0;
	if (i > size[1] && flag[4] && (size[1] != 0 || flag[4] == '.'))
		i = size[1];
	if (size[0] < 0)
		size[0] = -size[0];
	if (flag[2] == '-' )
	{
		write(1, source, i);
		while (size[0] > 0 && size[0] - i > 0)
			i += write(1, " ", 1);
	}
	else
	{
		j = i;
		while (size[0] > 0 && size[0] - i > 0)
			i += write(1, " ", 1);
		write(1, source, j);
	}
	return (i);
}

int	ft_printx(unsigned int source, long long *s, char x, char *fl)
{
	int	para_size;

	para_size = 0;
	if (fl[0] == '#' && x == 'x' && source != 0)
		para_size = ft_printpx(source, s, fl, "0x");
	else if (fl[0] == '#' && x == 'X' && source != 0)
		para_size = ft_printpx(source, s, fl, "0X");
	else if (x == 'X')
		para_size = ft_printpx(source, s, fl, NULL);
	else
		para_size = ft_printpx(source, s, fl, "");
	return (para_size);
}

int	ft_printp(void *source, long long *size, char *flag, char *p)
{
	int			i;
	char		*base;
	char		*hex;

	base = "0123456789abcdef";
	if (!p || *p == 'X' || p[1] == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	if (size[0] < 0)
		size[0] = -size[0];
	if (size[1] == 0 && flag[3] == '0')
		size[1] = size[1] - ft_strlen(p);
	hex = ft_base_16((unsigned long)source, base, size[1]);
	if (flag[2] == '-')
		i += write(1, p, ft_strlen(p)) + write(1, hex, ft_strlen(hex));
	while (flag[2] == '-' && size[0] - i > 0)
		i += write (1, " ", 1);
	while (flag[2] != '-' && (size[0] - ft_strlen(p) - ft_strlen(hex) - i) > 0)
		i += write (1, " ", 1);
	if (flag[2] != '-')
		i += write(1, p, ft_strlen(p)) + write(1, hex, ft_strlen(hex));
	free(hex);
	return (i);
}

int	ft_printu(unsigned int source, long long *size, char *flag)
{
	int		i;
	int		di;

	i = 0;
	di = ft_countdigit (source);
	if (size[1] != 0 && size[1] < di)
		size[1] = di;
	if (flag[2] != '-')
		i += ft_rightint(source, size, flag, di);
	else if (flag[2] == '-')
		i += ft_leftint(source, size, flag, di);
	return (i);
}
