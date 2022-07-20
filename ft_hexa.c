/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:33:57 by fothman           #+#    #+#             */
/*   Updated: 2022/07/21 00:33:59 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	hexa_change(uintptr_t num)
{
	if (num >= 16)
	{
		hexa_change(num / 16);
		hexa_change(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'A', 1);
	}
}

int	print_hexa(unsigned long hexadecimal, const char identifier)
{
	int	length;

	length = 0;
	if (hexadecimal == 0)
		length += write(1, "0", 1);
	else if (identifier == 'x')
	{
		pointer_change(hexadecimal);
		length += pointer_length(hexadecimal);
	}
	else if (identifier == 'X')
	{
		hexa_change(hexadecimal);
		length += pointer_length(hexadecimal);
	}
	return (length);
}
