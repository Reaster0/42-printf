/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:34:30 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/10 18:56:32 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_preci(t_flags *fl, int *nbr, const char **flags, va_list args)
{
	fl->preci = 0;
	(*nbr)++;
	if (**flags == '*')
	{
		fl->preci = va_arg(args, int);
		(*flags)++;
		(*nbr)++;
	}
	else
		while (ft_isdigit((int)**flags))
		{
			fl->preci *= 10;
			fl->preci += (int)**flags - '0';
			(*flags)++;
			(*nbr)++;
		}
}

static void	ft_fwidth(t_flags *fl, int *nbr, const char **flags, va_list args)
{
	if (**flags == '*')
	{
		fl->fwidth = va_arg(args, int);
		(*flags)++;
		(*nbr)++;
	}
	else
		while (ft_isdigit((int)**flags))
		{
			fl->fwidth *= 10;
			fl->fwidth += **flags - '0';
			(*flags)++;
			(*nbr)++;
		}
}

static void	ft_init_fix(t_flags *fl, int *nbr, char flags, int indic)
{
	if (!indic)
	{
		*nbr = 0;
		fl->minus = 0;
		fl->zero = 0;
		fl->fwidth = 0;
		fl->preci = -1;
	}
	else
	{
		if (fl->preci >= 0 && flags != '%')
			fl->zero = 0;
		if (fl->preci < 0)
			fl->preci = -1;
		if (fl->fwidth < 0)
		{
			fl->minus = 1;
			fl->fwidth *= -1;
		}
		if (fl->minus)
			fl->zero = 0;
	}
}

static void	srflags(t_flags *fl, const char **flags, va_list args, int *nbr)
{
	while (ft_strchr("-0.*123456789", **flags))
	{
		if (**flags == '-')
			fl->minus = 1;
		else if (**flags == '0')
			fl->zero = 1;
		else if (**flags == '.')
		{
			(*flags)++;
			ft_preci(fl, nbr, flags, args);
			if (*flags)
				continue;
		}
		else if (ft_isdigit((int)**flags) || **flags == '*')
		{
			ft_fwidth(fl, nbr, flags, args);
			continue;
		}
		(*flags)++;
		(*nbr)++;
	}
}

int			ft_parsarg(const char *flags, va_list args, int *result)
{
	t_flags	fl;
	int		nbr;

	ft_init_fix(&fl, &nbr, 0, 0);
	if (!ft_check_error("cspdiuxX%", flags))
		return (1);
	srflags(&fl, &flags, args, &nbr);
	ft_init_fix(&fl, &nbr, *flags, 42);
	*result += ft_conversion(fl, *flags, args);
	return (nbr);
}
