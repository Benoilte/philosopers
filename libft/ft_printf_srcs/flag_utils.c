/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:43:44 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/01 12:19:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Set in lst flag found after a '%' sign
*/
int	ft_set_flag(const char *str, t_printf_lst *lst)
{
	int		j;

	j = 0;
	while (ft_is_flag(str[j]) && str[j] != '\0')
	{
		if (str[j] == '0')
			lst->flag_zero = 1;
		if (str[j] == '+')
			lst->flag_plus = 1;
		if (str[j] == '-')
			lst->flag_minus = 1;
		if (str[j] == ' ')
			lst->flag_space = 1;
		if (str[j++] == '#')
			lst->flag_hash = 1;
	}
	return (j);
}

/*
Return 1 if 'c' char is a printf 'flag' if not return 0.
flags handled are '-' '0' '#' ' ' '+'
*/
int	ft_is_flag(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "-0# +";
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
flag '0' is ignored with flag '-' or if a precision is set.
flag ' ' is ignored if a flag '+' is present.
*/
void	ft_set_flag_priority(t_printf_lst *lst)
{
	if ((lst->flag_zero && lst->flag_minus)
		|| (lst->flag_zero && lst->precision >= 0))
		lst->flag_zero = 0;
	if (lst->flag_space && lst-> flag_plus)
		lst->flag_space = 0;
}
