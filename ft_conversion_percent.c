/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:25:25 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/09 17:38:11 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_conversion_percent(t_flags fl)
{
	int result;
	char padd;

	padd = ' ';
	if (fl.zero)
		padd = '0';
	result = 1;
	if (fl.minus)
		ft_putchar_fd('%', 1);
	while (fl.fwidth > 1)
	{
		result++;
		ft_putchar_fd(padd, 1);
		fl.fwidth--;
	}
	if (!fl.minus)
		ft_putchar_fd('%', 1);
	return (result);
}
