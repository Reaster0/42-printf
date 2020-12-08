/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:41:41 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/08 16:34:54 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		number_conv(char *final, int *result)
{
	int i;

	i = 0;
	(*result) += 2;
	ft_putstr_fd("0x", 1);
	while (final[i])
	{
		(*result)++;
		ft_putchar_fd(final[i], 1);
		i++;
	}
}

static void		fwidth(int width, int len, int *result)
{
	while (width > len + 2)
	{
		(*result)++;
		ft_putchar_fd(' ', 1);
		width--;
	}
}

int				ft_conversion_pointer(t_flags fl, va_list args)
{
	unsigned long	ptr;
	int				result;
	char			*final;

	result = 0;
	ptr = (unsigned long)va_arg(args, void *);
	final = ft_itoa_base(ptr, "0123456789abcdef");
	if (fl.preci == 0 && final[0] == '0')
		final[0] = '\0';
	if (fl.minus)
	{
		number_conv(final, &result);
		fwidth(fl.fwidth, ft_strlen(final), &result);
	}
	else
	{
		fwidth(fl.fwidth, ft_strlen(final), &result);
		number_conv(final, &result);
	}
	free(final);
	return (result);
}
