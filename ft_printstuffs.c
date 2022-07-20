/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstuffs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fothman <fothman@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:48:51 by fothman           #+#    #+#             */
/*   Updated: 2022/07/20 16:48:53 by fothman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

void	ft_normal_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putstr_length(char *str)
{
	int	char_count;

	char_count = 0;
	if (str == 0)
	{
		ft_normal_putstr("(null)");
		return (6);
	}
	while (str[char_count])
	{
		write(1, &str[char_count], 1);
		char_count++;
	}
	return (char_count);
}

int	ft_putnbr_length(int n)
{
	int		digit_count;
	char	*number;

	number = ft_itoa(n);
	digit_count = ft_putstr_length(number);
	free (number);
	return (digit_count);
}
