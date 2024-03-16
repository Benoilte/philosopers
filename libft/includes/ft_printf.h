/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:24:40 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/12 22:00:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct s_printf_lst
{
	int					flag_zero;
	int					flag_plus;
	int					flag_minus;
	int					flag_space;
	int					flag_hash;
	int					width;
	int					precision;
	char				specifier;
	struct s_printf_lst	*next;
}		t_printf_lst;

int				ft_printf(const char *format, ...);
int				ft_is_specifier(char c);
int				ft_set_flag(const char *str, t_printf_lst *lst);
void			ft_set_flag_priority(t_printf_lst *lst);
int				ft_is_flag(char c);
int				ft_print_arg(va_list args, t_printf_lst *lst);
int				ft_print_char(char c, t_printf_lst *lst);
int				ft_print_str(char *s, t_printf_lst *lst);
int				ft_print_ptr(void *p, t_printf_lst *lst);
int				ft_print_decimal(int n, t_printf_lst *lst);
int				ft_print_int(int n, t_printf_lst *lst);
int				ft_print_hex(unsigned int uint, t_printf_lst *lst);
int				ft_print_uint(unsigned int uint, t_printf_lst *lst);
int				ft_print_percent(t_printf_lst *lst);
int				ft_print_hex_format(char *hex_nbr, t_printf_lst *lst);
void			ft_print_width_fd(int width, int fd, int flag_zero);
void			ft_print_precision_fd(int len, int fd);
int				ft_print_zero_precision_fd(t_printf_lst *lst, int fd);

// setting lst

t_printf_lst	*set_new_lst(t_printf_lst *lst);
void			ft_set_ptr_lst(t_printf_lst *lst);

#endif
