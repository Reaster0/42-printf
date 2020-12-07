/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:03:50 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/07 16:34:07 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_conversion_char(t_flags fl, va_list arg)
{
	int	result;

	result = 1;
	if (fl.minus)
		ft_putchar_fd((char)va_arg(arg, int), 1);
	while (fl.fwidth > 1 )
	{
		result++;
		ft_putchar_fd(' ', 1);
		fl.fwidth--;
	}
	if (!fl.minus)
		ft_putchar_fd((char)va_arg(arg, int), 1);
	return (result);
}
