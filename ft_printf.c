/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/02 18:12:43 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_conversion_int(t_flags fl, va_list args)
{
	//cas ou -5.4
	//cas ou .1
	//cas ou 010 et -42
	char 	temp;
	int		value;
	char	*svalue;

	//en gros travaux
	value = va_arg(args, int);
	svalue = ft_itoa(value);
	temp = ' ';
	if (!fl.minus && fl.zero)
		temp = '0';
	if (fl.minus)
		ft_putnbr_fd(value, 1);
	while (fl.fwidth && fl.fwidth - ft_strlen(svalue) > 0 &&
			fl.fwidth - fl.preci > 0)
	{
		ft_putchar_fd(temp, 1);
		fl.fwidth--;
	}
	while (fl.preci && fl.preci - ft_strlen(svalue) > 0)
	{
		ft_putchar_fd('0', 1);;
		fl.preci--;
	}
	if (!fl.minus)
		ft_putnbr_fd(value, 1);
	free(svalue);
	return (1);
}

int		ft_conversion(t_flags fl, char conv, va_list args)
{
	if (conv == 'd' ||conv == 'i')
	{
		ft_conversion_int(fl, args);
	}
	return (1);
}

int		ft_parsarg(const char *flags, va_list args)
{
	t_flags	fl;
	int		nbr;

	//a mettre sous fonction
	nbr = 0;
	fl.minus = 0;
	fl.zero = 0;
	fl.fwidth = 0;
	fl.preci = -1;
	while (ft_strchr("-0.*123456789", *flags))
	{
		if (*flags == '-')
			fl.minus = 1;
		else if (*flags == '0')
			fl.zero = 1;
		else if (*flags == '.')
		{
			fl.preci = 0;
			nbr++;
			if (*(++flags) == '*')
			{
				fl.preci = va_arg(args, int);
				flags++;
				nbr++;
			}
			else
				while (ft_isdigit((int)*flags))
				{
					fl.preci *= 10;
					fl.preci += (int)*flags - '0';
					flags++;
						nbr++;
				}
			continue;
		}
		else if (ft_isdigit((int)*flags) || *flags == '*')
		{
			if (*flags == '*')
			{
				fl.fwidth = va_arg(args, int);
				flags++;
				nbr++;
			}
			else
				while (ft_isdigit((int)*flags))
				{
					fl.fwidth *= 10;
					fl.fwidth += *flags - '0';
					flags++;
					nbr++;
				}
			continue;
		}
		flags++;
		nbr++;
	}
	///faire un fix des valeurs selon mes notes
	if (fl.minus)
		fl.zero = 0;
	if (fl.preci >= 0)
		fl.zero = 0;
	if (fl.preci < 0)
		fl.preci = -1;
	if (fl.fwidth < 0)
	{
		fl.minus = 1;
		fl.fwidth *= -1;
	}
	//printf("\nfl.minus=%d\nfl.zero=%d\nft.fwidth=%d\nft.preci=%d\n",fl.minus,fl.zero,fl.fwidth,fl.preci);
	//ft_conversion(fl, *flags, args);
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
		{
			str++;
			str += ft_parsarg(str, params);
		}
		str++;
	}
	va_end(params);
	return (1);
}
