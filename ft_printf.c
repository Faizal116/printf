/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:41 by fothman           #+#    #+#             */
/*   Updated: 2022/07/20 16:49:43 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_characters(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_check_conversions(va_list args, const char identifier)
{
	int	printed_length;

	printed_length = 0;
	if (identifier == '%')
		printed_length += ft_percent();
	else if (identifier == 'c')
		printed_length += ft_print_characters(va_arg(args, int));
	else if (identifier == 'd' || identifier == 'i')
		printed_length += ft_putnbr_length(va_arg(args, int));
	else if (identifier == 's')
		printed_length += ft_putstr_length(va_arg(args, char *));
	else if (identifier == 'p')
	{
		printed_length += write(1, "0x", 2);
		printed_length += print_pointer(va_arg(args, unsigned long long));
	}
	else if (identifier == 'u')
		printed_length += print_unsigned(va_arg(args, unsigned int));
	else if (identifier == 'x' || identifier == 'X')
		printed_length += print_hexa(va_arg(args, unsigned int), identifier);
	return (printed_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_check_conversions(args, str[i + 1]);
			i++;
		}
		else
			count += ft_print_characters(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
