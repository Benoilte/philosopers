/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:20:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_printstr_fd(char *s, int fd, int len);

/*
Print str with its corresponding flag, width and precision.
only flag '-' width and precision are accepted.
if precision < str_len => str is truncated.
*/
int	ft_print_str(char *s, t_printf_lst *lst)
{
	int		str_len;

	if (!s)
		s = "(null)";
	str_len = ft_strlen(s);
	if (lst->precision >= 0 && lst->precision < str_len)
		str_len = lst->precision;
	if (lst->flag_minus && lst->width > str_len)
	{
		ft_printstr_fd(s, 1, str_len);
		ft_print_width_fd(lst->width - str_len, 1, 0);
		return (lst->width);
	}
	else if (lst->width > str_len)
	{
		ft_print_width_fd(lst->width - str_len, 1, 0);
		ft_printstr_fd(s, 1, str_len);
		return (lst->width);
	}
	else
	{
		ft_printstr_fd(s, 1, str_len);
		return (str_len);
	}
}

static void	ft_printstr_fd(char *s, int fd, int len)
{
	while (len > 0)
	{
		ft_putchar_fd(*s, fd);
		len--;
		s++;
	}
}
