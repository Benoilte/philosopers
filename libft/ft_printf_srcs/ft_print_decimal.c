/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:21:58 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_compute_nbr_len(int n, char *nbr, t_printf_lst *lst);
static void	ft_print_nbr(char *nbr, int n, t_printf_lst *lst);
static void	ft_print_plus_space_flag(int n, t_printf_lst *lst);

/*
Print decimal base 10 with its corresponding flag, width and precision.
only flag '#' is NOT supported.
*/
int	ft_print_decimal(int n, t_printf_lst *lst)
{
	char	*nbr;
	int		str_len;

	if (lst->precision == 0 && n == 0)
		return (ft_print_zero_precision_fd(lst, 1));
	nbr = ft_itoa(n);
	str_len = ft_compute_nbr_len(n, nbr, lst);
	if (lst->flag_minus && lst->width > str_len)
	{
		ft_print_nbr(nbr, n, lst);
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
	}
	else if (lst->width > str_len && !lst->flag_zero)
	{
		ft_print_width_fd(lst->width - str_len, 1, lst->flag_zero);
		ft_print_nbr(nbr, n, lst);
	}
	else
		ft_print_nbr(nbr, n, lst);
	free(nbr);
	if (lst->width > str_len)
		return (lst->width);
	return (str_len);
}

/*
compute the length of the number to be printed
according to its flags, width and precision
*/
static int	ft_compute_nbr_len(int n, char *nbr, t_printf_lst *lst)
{
	int		str_len;

	str_len = ft_strlen(nbr);
	if (lst->precision >= str_len)
	{
		str_len = lst->precision;
		if (n < 0)
			str_len++;
	}
	if ((lst->flag_plus || lst->flag_space) && n >= 0)
		str_len += 1;
	return (str_len);
}

/*
Print number with its corresponding flags
*/
static void	ft_print_nbr(char *nbr, int n, t_printf_lst *lst)
{
	int	i;
	int	nbr_len;

	i = 0;
	nbr_len = (int)ft_strlen(nbr);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i = 1;
		if (lst->precision > (nbr_len - 1))
			nbr_len--;
	}
	if (lst->flag_zero && n >= 0 && (lst->flag_space || lst->flag_plus))
		nbr_len++;
	ft_print_plus_space_flag(n, lst);
	if (lst->precision > nbr_len)
		ft_print_precision_fd(lst->precision - nbr_len, 1);
	else if (lst->width > nbr_len && lst->flag_zero)
		ft_print_width_fd(lst->width - nbr_len, 1, lst->flag_zero);
	ft_putstr_fd(nbr + i, 1);
}

/*
Print flag ' ' or '+' if n >= 0;
*/
static void	ft_print_plus_space_flag(int n, t_printf_lst *lst)
{
	if (n < 0)
		return ;
	else if (lst->flag_plus)
		ft_putchar_fd('+', 1);
	else if (lst->flag_space)
		ft_putchar_fd(' ', 1);
}
