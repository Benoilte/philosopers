/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:04 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/21 18:04:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_parse_format(const char *format, va_list args);
static void	ft_print_format(const char *str, int *i, int *len);
static void	ft_get_flags_specifier(const char *str, int *i, t_printf_lst *lst);
static int	ft_get_digit(const char *s, int *i);

/*
Copy of lib_c printf. Print format string with its variables passed as argument
if a '%' sign is in the string. flag ['-' '0' '#' ' ' '+'], width and precision
are accepted.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	len = ft_parse_format(format, args);
	va_end(args);
	return (len);
}

/*
Go through string 'format' count char printed.
if '%' sign is found -> parse until a following specifier [cspdiuxX%] is found.
create a new lst with flag - width - precision and specifier.
return the length of the format string printed.
*/
static int	ft_parse_format(const char *format, va_list args)
{
	int				len;
	int				i;
	t_printf_lst	*lst;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			lst = set_new_lst(lst);
			ft_get_flags_specifier(format + i, &i, lst);
			if (!ft_is_specifier(lst->specifier))
				return (-1);
			len += ft_print_arg(args, lst);
			free(lst);
			i++;
		}
		else
			ft_print_format(format + i, &i, &len);
	}
	return (len);
}

/*
Print char increment flag i and str length by one
*/
static void	ft_print_format(const char *str, int *i, int *len)
{
	ft_putchar_fd(*str, 1);
	*i += 1;
	*len += 1;
}

/*
Get and set lst according to flag, width, precision and specifier after '%' sign.
*/
static void	ft_get_flags_specifier(const char *str, int *i, t_printf_lst *lst)
{
	int		j;

	j = ft_set_flag(str, lst);
	if (ft_isdigit(str[j]))
		lst->width = ft_get_digit(str + j, &j);
	if (str[j] == '.')
	{
		lst->precision = 0;
		if (ft_isdigit(str[++j]))
			lst->precision = ft_get_digit(str + j, &j);
	}
	if (ft_is_specifier(str[j]))
		lst->specifier = str[j];
	ft_set_flag_priority(lst);
	*i += j;
}

/*
Return the integer found in a string. 
's' should be the first position of a digital char. 
"42hel5lo88" => 42;
*/
static int	ft_get_digit(const char *s, int *j)
{
	int		end;
	int		num;
	char	*str_digit;

	end = 0;
	end = 1;
	while (ft_isdigit(s[end]) && s[end])
		end++;
	str_digit = ft_substr(s, 0, end);
	num = ft_atoi(str_digit);
	free(str_digit);
	*j += end;
	return (num);
}
