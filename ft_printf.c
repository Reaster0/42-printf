/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:49:01 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conversion_int0(t_flags *fl,int value,char **svalue,int *no0)
{
	*no0 = 0;
	if (fl->preci == 0 && value == 0)
	{
		*no0 = 1;
		*svalue = ft_strdup("");
	}
	else
		*svalue = ft_itoa(value);
	if (fl->preci < 0)
		fl->preci = 0;	
}

int		ft_conversion(t_flags fl, char conv, va_list args)
{
	if (conv == 'd' || conv == 'i')
		return (ft_conversion_int(fl, args));
	return (0);
}

int		ft_nbrlen(long int nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
		nbr *= -1;
	while(nbr /= 10)
		i++;
	return (i);
}

int		ft_parsarg(const char *flags, va_list args,int *result)
{
	t_flags	fl;
	int		nbr;

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
	*result += ft_conversion(fl, *flags, args);
	return (nbr);
}

int ft_printf(const char *str, ...)
{
	va_list params;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start (params, str);
	while ((*str))
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			result++;
		}
		else
		{
			str++;
			str += ft_parsarg(str, params, &result);
		}
		str++;
	}
	va_end(params);
	return (result);
}
