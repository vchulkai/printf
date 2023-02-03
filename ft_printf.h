/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchulkai <vchulkai@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:06:29 by vchulkai          #+#    #+#             */
/*   Updated: 2023/02/02 22:19:21 by vchulkai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
char		*ft_checkflag(const char **f);
long long	check_size(const char **format, char **flag);
long long	check_precision(const char **format, char **flag);
int			printf_con(va_list *args, char *fl, long long *s, const char **f);
int			ft_prints(char *source, long long *size, char *flag);
long long	ft_strlen(const char *s);
int			ft_printc(char source, long long *size, char flag);
int			ft_printp(void *source, long long *size, char *flag, char *prefix);
char		*ft_base_16(unsigned long s, char *str, long long size1);
int			ft_printi(int source, long long *size, char *flag);
int			ft_countdigit(long long number);
int			print_digits(long long number);
int			ft_leftint(long long source, long long *size, char *flag, int di);
int			ft_rightint(long long source, long long *size, char *flag, int di);
int			ft_printu(unsigned int source, long long *size, char *flag);
int			ft_printx(unsigned int source, long long *s, char x, char *fl);
char		*check_assign_null(char *chnull);
int			ft_printpx(unsigned int s, long long *size, char *flag, char *p);
int			ft_printpxcom1(unsigned int s, long long *size, char *hex, char *p);
int			ft_printpxcom2(unsigned int s, long long *size, char *hex, char *p);
int			ft_printpxcom3(char *flag, long long *size, char *hex, char *p);
int			ft_rightintcom1(long long s, long long *si, char *f);
int			ft_rightintcom2(long long s, long long *si, char *f, int di);
int			ft_rightintcom3(long long s, long long *si, int di);
int			ft_rightintcom4(long long s, long long *si, char *f, int di);
int			ft_rightintcom5(long long s, long long *si, char *f, int di);

#endif
