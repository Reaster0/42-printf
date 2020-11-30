/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/30 13:45:26 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parsarg(const char *arg)
{
	int	ret;

	ret = 0;
	while (!(ft_strchr("cspdiuxX%", *arg)))
	{
		if (*arg == '-' && ret % 10 < 1)
			ret += 1;
		if (*arg == '0' && ret % 100 < 10)
			ret += 10;
		arg++;
	}
	printf("\nvaleur de ret =%d\n",ret);
	return (ret);
}

int ft_printf(const char *str, ...)
{
	va_list params;
	int		i = 0;
	char	current;
	int		flags;

	va_start (params, str);
	while ((current = *str))
	{
		str++;
		if (current != '%')
		{
			ft_putchar_fd(current, 1);
			continue ;
		}
		flags = ft_parsarg(str);
		break;
	}
	while (flags / 10)
	{
	printf("%d",flags);	
		flags /= 10;
	}
	va_end(params);
	return (1);
}
