/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:34:13 by fothman           #+#    #+#             */
/*   Updated: 2022/07/21 00:34:14 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_length(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*uns_itoa(unsigned int n)
{
	char	*asc;
	int		digit;

	digit = count_length(n);
	asc = malloc(sizeof(char) * (digit + 1));
	if (!asc)
		return (0);
	*(asc + digit) = 0;
	while (n != 0)
	{
		asc[digit - 1] = n % 10 + 48;
		n = n / 10;
		digit--;
	}
	return (asc);
}

int	print_unsigned(unsigned int n)
{
	int		length;
	char	*number;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		number = uns_itoa(n);
		length += ft_putstr_length(number);
		free (number);
	}
	return (length);
}
