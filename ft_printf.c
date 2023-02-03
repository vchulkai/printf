/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:08:39 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:27:57 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*flag;
	long long	size[2];
	int			count;

	count = 0;
	va_start (args, format);
	while (*format != '\0')
	{
		size[0] = 0;
		size[1] = 0;
		if (*format++ == '%')
		{
			flag = ft_checkflag(&format);
			size[0] = check_size(&format, &flag);
			if (flag[4] == '.')
				size[1] = check_precision(&format, &flag);
			count += printf_con(&args, flag, size, &format);
			free(flag);
		}
		else
			count += write(1, (format - 1), 1);
	}
	va_end (args);
	return (count);
}

char	*ft_checkflag(const char **f)
{
	char	*flag;

	flag = malloc(6);
	while (**f == '#' || **f == '+' || **f == '-' || **f == '0' || **f == '.'
		|| **f == ' ')
	{
		if (**f == '#')
			flag[0] = '#';
		else if (**f == '+')
			flag[1] = '+';
		else if (**f == '-')
			flag[2] = '-';
		else if (**f == '0')
			flag[3] = '0';
		else if (**f == '.')
			flag[4] = '.';
		else if (**f == ' ')
			flag[5] = ' ';
		(*f)++;
	}
	return (flag);
}

long long	check_size(const char **format, char **flag)
{
	size_t	size;

	size = 0;
	while (**format >= '0' && **format <= '9' && (*flag)[4] != '.')
	{
		size = 10 * size + (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		(*flag)[4] = '.';
		(*format)++;
	}
	return (size);
}

long long	check_precision(const char **format, char **flag)
{
	long long	i;

	i = 0;
	if (**format == '0')
	{
		(*flag)[3] = '0';
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
	{
		i = 10 * i + (**format - '0');
		(*format)++;
	}
	return (i);
}

int	printf_con(va_list *args, char *fl, long long *s, const char **f)
{
	int	para_size;

	para_size = 0;
	if (**f == '%')
		para_size = write (1, "%", 1);
	else if (**f == 's')
		para_size = ft_prints(va_arg(*args, char *), s, fl);
	else if (**f == 'c')
		para_size = ft_printc(va_arg(*args, int), s, fl[2]);
	else if (**f == 'p')
		para_size = ft_printp(va_arg(*args, void *), s, fl, "0x");
	else if (**f == 'i' || **f == 'd')
		para_size = ft_printi(va_arg(*args, int), s, fl);
	else if (**f == 'u')
		para_size = ft_printu(va_arg(*args, unsigned int), s, fl);
	else if (**f == 'X' || **f == 'x')
		para_size = ft_printx(va_arg(*args, unsigned int), s, **f, fl);
	(*f)++;
	return (para_size);
}
