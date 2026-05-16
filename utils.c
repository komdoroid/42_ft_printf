/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:06:58 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 14:08:47 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putuint(unsigned int	num)
{
	char	digit;
	int		count;

	count = 0;
	if (num / 10 != 0)
		count += ft_putuint(num / 10);
	digit = '0' + num % 10;
	write(1, &digit, 1);
	count++;
	return (count);
}

int	ft_puthex(unsigned long num, char *base)
{
	int		count;

	count = 0;
	if (num / 16 != 0)
		count += ft_puthex(num / 16, base);
	write(1, &base[num % 16], 1);
	count++;
	return (count);
}
