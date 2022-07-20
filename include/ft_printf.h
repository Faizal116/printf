/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:34:50 by fothman           #+#    #+#             */
/*   Updated: 2022/07/21 00:34:51 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		print_hexa(unsigned long hexadecimal, const char identifier);
void	hexa_change(uintptr_t num);
char	*uns_itoa(unsigned int n);
int		print_unsigned(unsigned int n);
int		ft_print_characters(int character);
int		ft_check_conversions(va_list args, const char identifier);
int		print_pointer(unsigned long long pointer);
int		pointer_length(uintptr_t num);
void	pointer_change(uintptr_t num);
int		ft_percent(void);
void	ft_normal_putstr(char *str);
int		ft_putstr_length(char *str);
int		ft_putnbr_length(int n);

#endif
