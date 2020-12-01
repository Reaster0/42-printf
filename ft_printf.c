/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/01 19:54:47 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_parsarg(const char *flags, va_list args)
{
	t_flags	fl;
	int		nbr;

	nbr = 0;
	fl.minus = 0;
	fl.zero = 0;
	fl.fwidth = 0;
	fl.precision = 0;
	while (ft_strchr("-0.*", *flags))
	{
		if (*flags == '-')
			fl.minus = 1;
		if (*flags == '0')
			fl.zero = 1;
		if (*flags == '.')
		{
			if (*(flags++) == '*')
				fl.precision = va_arg(args, int);
			else
				while (ft_isdigit((int)*flags))
				{
					fl.precision *= 10;
					fl.precision += (int)*flags - '0';
					flags++;
					nbr++;
				}
			nbr++;
			continue;
		}
		flags++;
		nbr++;
	}
	while (ft_isdigit((int)*flags))
	{
		fl.fwidth *= 10;
		fl.fwidth += *flags - '0';
		flags++;
		nbr++;
	}
	printf("\nle nombre de char flags lus =%d\n",nbr);
	printf("\nfl minus =%d\n",fl.minus);
	printf("\nfl zero =%d\n",fl.zero);
	printf("\nfl precision =%d\n",fl.precision);
	printf("\nfl fwidth =%d\n",fl.fwidth);
	return (nbr);
}

int ft_printf(const char *str, ...)
{
	va_list params;
	int		i = 0;

	va_start (params, str);
	while ((*str))
	{
		if (*str != '%')
			ft_putchar_fd(*str, 1);
		else
		str += ft_parsarg(str, params);
		str++;
	}
	va_end(params);
	return (1);
}
