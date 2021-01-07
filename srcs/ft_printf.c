/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/11 17:37:59 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion(t_flags fl, char conv, va_list args)
{
	if (conv == 'd' || conv == 'i')
		return (ft_conversion_int(fl, args));
	if (conv == 'c')
		return (ft_conversion_char(fl, args));
	if (conv == 's')
		return (ft_conversion_string(fl, args));
	if (conv == 'p')
		return (ft_conversion_pointer(fl, args));
	if (conv == 'u')
		return (ft_conversion_unsign(fl, args));
	if (conv == 'x' || conv == 'X')
		return (ft_conversion_hexa(fl, args, conv));
	if (conv == '%')
		return (ft_conversion_percent(fl));
	return (0);
}

int		ft_check_error(char *param, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(param, str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list params;
	int		result;

	result = 0;
	va_start(params, str);
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
