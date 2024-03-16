/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:23:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_print_ui_nbr(char *ui_nbr, t_printf_lst *lst);

/*
Print unsigned int with its corresponding flag, width and precision.
only flag '0', '-', width and precision are accepted.
*/
int	ft_print_uint(unsigned int uint, t_printf_lst *lst)
{
	char	*ui_nbr;
	int		str_len;

	if (lst->precision == 0 && uint == 0)
		return (ft_print_zero_precision_fd(lst, 1));
	ui_nbr = ft_itoa_uint(uint);
	str_len = ft_strlen(ui_nbr);
	if (lst->precision > str_len)
		str_len = lst->precision;
	if (lst->flag_minus && lst->width > str_len)
	{
		ft_print_ui_nbr(ui_nbr, lst);
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
	}
	else if (lst->width > str_len)
	{
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
		ft_print_ui_nbr(ui_nbr, lst);
	}
	else
		ft_print_ui_nbr(ui_nbr, lst);
	free(ui_nbr);
	if (lst->width > str_len)
		return (lst->width);
	return (str_len);
}

/*
Print unsigned int according to its flags, width and precision.
*/
static void	ft_print_ui_nbr(char *ui_nbr, t_printf_lst *lst)
{
	int		i;

	i = 0;
	if (lst->precision > (int)ft_strlen(ui_nbr))
		ft_print_precision_fd(lst->precision - ft_strlen(ui_nbr), 1);
	while (ui_nbr[i])
		ft_putchar_fd(ui_nbr[i++], 1);
}
