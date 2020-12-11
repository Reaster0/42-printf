/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:44:17 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/11 17:35:35 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_string(t_flags fl, char *str, int *result)
{
	int		i;
	char	*null;

	null = ft_strdup("(null)");
	i = 0;
	if (!str)
	{
		while (null[i] && i != fl.preci)
		{
			(*result)++;
			ft_putchar_fd(null[i], 1);
			i++;
		}
	}
	else
		while (str[i] && i != fl.preci)
		{
			(*result)++;
			ft_putchar_fd(*(str + i), 1);
			i++;
		}
	free(null);
}

static void		ft_fwidth(t_flags fl, char *str, int *result)
{
	int len;

	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (fl.fwidth > len || (fl.fwidth > fl.preci && fl.preci != -1))
	{
		(*result)++;
		if (fl.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		fl.fwidth--;
	}
}

int				ft_conversion_string(t_flags fl, va_list args)
{
	int		result;
	char	*str;

	result = 0;
	str = va_arg(args, char*);
	if (fl.minus)
	{
		ft_string(fl, str, &result);
		ft_fwidth(fl, str, &result);
	}
	else
	{
		ft_fwidth(fl, str, &result);
		ft_string(fl, str, &result);
	}
	return (result);
}
