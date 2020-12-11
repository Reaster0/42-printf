/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:57:37 by earnaud           #+#    #+#             */
/*   Updated: 2020/12/11 16:12:24 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_flags
{
	int				minus;
	int				zero;
	int				fwidth;
	int				preci;
}					t_flags;

char				*ft_itoa_base(long long n, char *base);
int					ft_printf(char const *str, ...);
int					ft_parsarg(const char *flags, va_list args, int *result);
int					ft_check_error(char *param, const char *str);
int					ft_conversion(t_flags fl, char conv, va_list args);
int					ft_conversion_int(t_flags fl, va_list args);
int					ft_conversion_char(t_flags fl, va_list args);
int					ft_conversion_pointer(t_flags fl, va_list args);
int					ft_conversion_string(t_flags fl, va_list args);
int					ft_conversion_unsign(t_flags fl, va_list args);
int					ft_conversion_hexa(t_flags fl, va_list args, char l_c);
int					ft_conversion_percent(t_flags fl);

#endif
