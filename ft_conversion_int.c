/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:44:59 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/04 18:42:08 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_conversion_int1b(t_flags *fl,int *value, char **svalue)
{
	char temp;
	char result;

	temp = ' ';
	if (fl->zero)
		temp = '0';
	result = 0;
	while (fl->fwidth && !fl->minus && fl->fwidth > (long int)ft_strlen(*svalue)
			&& fl->fwidth > (fl->preci + (long int)ft_strlen(*svalue)) -
			ft_nbrlen((long int)*value))
	{
		if (*value < 0 && fl->zero)
		{
			result++;
			ft_putchar_fd('-', 1);
			*value *= -1;
		}
		result++;
		ft_putchar_fd(temp, 1);
		fl->fwidth--;
	}
	return (result);
}

int     ft_conversion_int1(t_flags *fl, int *value, char **svalue, int no0)
{
	char temp;
	int result;

	result = 0;
	temp = ' ';
	if (fl->zero)
		temp = '0';
	if (!no0 && fl->minus && fl->preci < (long int)ft_strlen(*svalue))
	{
		result++;
		ft_putnbr_fd(*value, 1);
	}
	result += ft_conversion_int1b(fl,value,svalue);
	return (result);
}

int     ft_conversion_int2b(t_flags *fl,int *value,char **svalue)
{
	int result;

	result = 0;
	while (fl->preci && fl->preci > ft_nbrlen((long int)*value))
	{
		if (*value < 0)
		{
			result++;
			ft_putchar_fd('-', 1);
			*value *= -1;
		}
		result++;
		ft_putchar_fd('0', 1);
		fl->preci--;
	}
	return (result);
}

int     ft_conversion_int2(t_flags *fl,int *value,int no0,char **svalue)
{
	int tempreci;
	char temp;
	int result;

	result = 0;
	temp = ' ';
	if (fl->zero)
		temp = '0';
	tempreci = fl->preci;
	result += ft_conversion_int2b(fl,value,svalue);
	if (!no0 && (!fl->minus || (fl->preci >= ft_nbrlen(*value) &&
					(*value > -1 || *value < -9))))
	{
		result++;
		ft_putnbr_fd(*value, 1);
	}
	while (fl->fwidth && fl->minus && fl->fwidth > (long int)ft_strlen(*svalue)
			&& fl->fwidth > (tempreci +
				(long int)ft_strlen(*svalue)) - ft_nbrlen((long int)*value))
	{
		result++;
		ft_putchar_fd(temp, 1);
		fl->fwidth--;
	}
	return (result);
}

int     ft_conversion_int(t_flags fl, va_list args)
{
	char    temp;
	int     value;
	char    *svalue;
	int     no0;
	char    result;

	result = 0;
	value = va_arg(args, int);
	ft_conversion_int0(&fl,value,&svalue,&no0);
	result += ft_conversion_int1(&fl,&value,&svalue,no0);
	result += ft_conversion_int2(&fl,&value,no0,&svalue);
	free(svalue);
	return (result);
}
