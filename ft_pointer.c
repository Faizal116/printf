/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:02 by fothman           #+#    #+#             */
/*   Updated: 2022/07/20 16:49:04 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pointer_change(uintptr_t num)
{
	if (num >= 16)
	{
		pointer_change(num / 16);
		pointer_change(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}

int	pointer_length(uintptr_t num)
{
	int	length;

	length = 0;
	while (num)
	{
		num /= 16;
		length++;
	}
	return (length);
}

int	print_pointer(unsigned long long pointer)
{
	int	length;

	length = 0;
	if (pointer == 0)
		length += write(1, "0", 1);
	else
	{
		pointer_change(pointer);
		length += pointer_length(pointer);
	}
	return (length);
}
