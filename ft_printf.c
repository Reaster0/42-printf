/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/30 19:53:30 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parsarg(const char *arg)
{
	t_flags	fl;

	fl.minus = 0;
	fl.zero = 0;
	fl.fwidth = 0;
	while (ft_strchr("-0", *arg))
	{
		if (*arg == '-')
			fl.minus = 1;
		if (*arg == '0')
			fl.zero = 1;
		arg++;
	}
	while (ft_isdigit((int)*arg))
	{
		fl.fwidth *= 10;
		fl.fwidth += *arg - '0';
		arg++;
	}
	printf("\nfl minus =%d\n",fl.minus);
	printf("\nfl zero =%d\n",fl.zero);
	printf("\nfl fwidth =%d\n",fl.fwidth);
}

int ft_printf(const char *str, ...)
{
	va_list params;
	int		i = 0;
	char	current;

	va_start (params, str);
	while ((current = *str))
	{
		str++;
		if (current != '%')
		{
			ft_putchar_fd(current, 1);
			continue ;
		}
		ft_parsarg(str);
		break;
	}
	va_end(params);
	return (1);
}
