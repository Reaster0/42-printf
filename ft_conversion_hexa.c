/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:29:20 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/09 18:15:13 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		width(t_flags fl, char *hex)
{
	int		result;
	int		max;
	char	padd;

	result = 0;
	padd = ' ';
	if (fl.zero)
		padd = '0';
	max = fl.preci;
	if (fl.preci < (long int)ft_strlen(hex))
		max = (long int)ft_strlen(hex);
	while (fl.fwidth > max)
	{
		result++;
		ft_putchar_fd(padd, 1);
		fl.fwidth--;
	}
	return (result);
}

static int		ft_hexa(t_flags fl, char *hexa)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (fl.preci > (long int)ft_strlen(hexa))
	{
		ft_putchar_fd('0', 1);
		result++;
		fl.preci--;
	}
	while (hexa[i])
	{
		ft_putchar_fd(hexa[i], 1);
		result++;
		i++;
	}
	return (result);
}

int				ft_conversion_hexa(t_flags fl, va_list args, char l_c)
{
	int		result;
	char	*final;

	result = 0;
	if (l_c == 'x')
		final = ft_itoa_base(va_arg(args, long long), "0123456789abcdef");
	else
		final = ft_itoa_base(va_arg(args, long long), "0123456789ABCDEF");
	if (final[0] == '0' && fl.preci != -1)
		final[0] = '\0';
	if (fl.minus)
	{
		result += ft_hexa(fl, final);
		result += width(fl, final);
	}
	else
	{
		result += width(fl, final);
		result += ft_hexa(fl, final);
	}
	free(final);
	return (result);
}
