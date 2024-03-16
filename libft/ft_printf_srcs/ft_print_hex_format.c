/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:33:41 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_print_hex_nbr(char *hex_nbr, int len, t_printf_lst *lst);
static void	ft_print_hash_flag(char *hex_nbr, t_printf_lst *lst);

/*
Print hexadecimal number with its corresponding flag, width and precision.
Flag '+' and ' ' are NOT supported.
*/
int	ft_print_hex_format(char *hex_nbr, t_printf_lst *lst)
{
	int		str_len;

	str_len = ft_strlen(hex_nbr);
	if (lst->precision > str_len)
		str_len = lst->precision;
	if ((lst->flag_hash && hex_nbr[0] != '0') || (lst->specifier == 'p'))
		str_len += 2;
	if (lst->flag_minus && lst->width > str_len)
	{
		ft_print_hex_nbr(hex_nbr, str_len, lst);
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
	}
	else if (lst->width > str_len && !lst->flag_zero)
	{
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
		ft_print_hex_nbr(hex_nbr, str_len, lst);
	}
	else
		ft_print_hex_nbr(hex_nbr, str_len, lst);
	free(hex_nbr);
	if (lst->width > str_len)
		return (lst->width);
	return (str_len);
}

/*
Print hexadecimal number with its corresponding flags.
if specifier == 'X' print in uppercase letter.
*/
static void	ft_print_hex_nbr(char *hex_nbr, int len, t_printf_lst *lst)
{
	int		i;

	i = 0;
	ft_print_hash_flag(hex_nbr, lst);
	if (lst->precision > (int)ft_strlen(hex_nbr))
		ft_print_precision_fd(lst->precision - ft_strlen(hex_nbr), 1);
	if (lst->width > len && lst->flag_zero)
		ft_print_width_fd(lst->width - len, 1, lst->flag_zero);
	while (hex_nbr[i])
	{
		if (lst->specifier == 'X')
			ft_putchar_fd(ft_toupper(hex_nbr[i]), 1);
		else
			ft_putchar_fd(hex_nbr[i], 1);
		i++;
	}
}

/*
specifier 'p' => print 0x;
specifier 'x' => print 0x;
specifier 'X' => print 0X;
*/
static void	ft_print_hash_flag(char *hex_nbr, t_printf_lst *lst)
{
	if (lst->specifier == 'p')
	{
		ft_putstr_fd("0x", 1);
		return ;
	}
	if (lst->flag_hash && hex_nbr[0] != '0')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(lst->specifier, 1);
	}
}
