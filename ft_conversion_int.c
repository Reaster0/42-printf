/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:44:59 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/07 15:07:00 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int value)
{
	int i;

	i = 1;
	if (value < 0)
		value = -value;
	while (value /= 10)
		i++;
	return (i);
}

int		ft_fwidth(t_flags fl, int *value, char *svalue, char padd)
{
	int			result;
	int			max;

	result = 0;
	max = fl.preci;
	if (fl.preci < (long int)ft_strlen(svalue))
		max = (long int)ft_strlen(svalue);
	else if (svalue[0] == '-')
		max++;
	while (fl.fwidth > max)
	{
		result++;
		if (*value < 0 && (fl.zero || fl.fwidth - 1 == fl.preci))
		{
			ft_putchar_fd('-', 1);
			*value = -*value;
			if (fl.fwidth > max)
				continue ;
		}
		else
			ft_putchar_fd(padd, 1);
		fl.fwidth--;
	}
	return (result);
}

int		ft_number(t_flags fl, int *value)
{
	int result;

	result = 0;
	if (!(fl.preci == 0 && *value == 0))
	{
		result += ft_nbrlen(*value);
		ft_putnbr_fd(*value, 1);
	}
	else if (fl.fwidth)
	{
		result++;
		ft_putchar_fd(' ', 1);
	}
	if (*value < 0)
		*value = -*value;
	return (result);
}

int		ft_preci(t_flags fl, int *value)
{
	int		result;

	result = 0;
	if (*value < 0)
	{
		result++;
		ft_putchar_fd('-', 1);
		*value = -*value;
	}
	while (fl.preci > ft_nbrlen(*value))
	{
		result++;
		ft_putchar_fd('0', 1);
		fl.preci--;
	}
	result += ft_number(fl, value);
	return (result);
}

int		ft_conversion_int(t_flags fl, va_list args)
{
	int		result;
	int		value;
	char	*svalue;
	char	padd;

	value = va_arg(args, int);
	svalue = ft_itoa(value);
	result = 0;
	padd = ' ';
	if (fl.zero)
		padd = '0';
	if (fl.minus)
	{
		result += ft_preci(fl, &value);
		result += ft_fwidth(fl, &value, svalue, padd);
	}
	else
	{
		result += ft_fwidth(fl, &value, svalue, padd);
		result += ft_preci(fl, &value);
	}
	free(svalue);
	return (result);
}
