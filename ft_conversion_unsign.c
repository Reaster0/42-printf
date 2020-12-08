/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_unsign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:01:52 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/08 18:26:46 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(long unsigned int value)
{
	int i;

	i = 1;
	while (value /= 10)
		i++;
	return (i);
}

static int		ft_fwidth(t_flags fl, char *svalue, char padd)
{
	int		result;
	int		max;

	result = 0;
	max = fl.preci;
	if (fl.preci < (long int)ft_strlen(svalue))
		max = (long int)ft_strlen(svalue);
	while (fl.fwidth > max)
	{
		result++;
		ft_putchar_fd(padd, 1);
		fl.fwidth--;
	}
	return (result);
}

static int		ft_number(t_flags fl, long unsigned int *value)
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
	return (result);
}

static int		ft_preci(t_flags fl, long unsigned int *value)
{
	int		result;

	result = 0;
	while (fl.preci > ft_nbrlen(*value))
	{
		result++;
		ft_putchar_fd('0', 1);
		fl.preci--;
	}
	result += ft_number(fl, value);
	return (result);
}

int				ft_conversion_unsign(t_flags fl, va_list arg)
{
	unsigned int		result;
	long unsigned int	value;
	char				*svalue;
	char				padd;

	value = va_arg(arg, long unsigned int);
	svalue = ft_itoa_base(value, "0123456789");
	result = 0;
	padd = ' ';
	if (fl.zero)
		padd = '0';
	if (fl.minus)
	{
		result += ft_preci(fl, &value);
		result += ft_fwidth(fl, svalue, padd);
	}
	else
	{
		result += ft_fwidth(fl, svalue, padd);
		result += ft_preci(fl, &value);
	}
	free(svalue);
	return (result);
}
