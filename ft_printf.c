/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:34:12 by earnaud           #+#    #+#             */
/*   Updated: 2020/11/30 19:31:56 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_isnew(t_list **lst, void *content)
{
	while (lst)
	{
		if ((unsigned char)(*lst)->content == (unsigned char)content + i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_parsarg(const char *arg)
{
	t_list 	result;
	t_list 	temp;
	char	*fwidth;

	fwidth = 0;
	while (ft_strchr("-0", *arg) && arg)
	{
		if (*arg == '-' && ft_lst_isnew(result, (void *)'-'))
		{
			temp = ft_lstnew((void *)'-')
				ft_lstadd_back(*result, temp);
			free(temp);
		}
		if (*arg == '0' && ft_lst_isnew(result, (void *)'0'))
		{
			temp = ft_lstnew((void *)'0')
				ft_lstadd_back(*result, temp);
			free(temp);
		}
		arg++;
	}
	if (ft_isdigit((int)*arg))
	{
		while (ft_isdigit((int)*arg))
		{
			*fwidth = *arg;
			fwidth++;
			arg++;
		}
		temp = ft_lstnew(void *)fwidth;
	}
	return (result);
}

int ft_printf(const char *str, ...)
{
	va_list params;
	int		i = 0;
	char	current;
	t_list	flags;

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
	while (flags)
	{
		ft_putstr_fd((char *)flags->content,1);
		flags = flags->next;
	}
	free(flags);
	va_end(params);
	return (1);
}
