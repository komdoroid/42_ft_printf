/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:06:58 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 16:50:05 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i])
	{
		ret = write(1, &str[i], 1);
		if (ret == -1)
			return (ret);
		i++;
	}
	return (i);
}

int	ft_putuint(unsigned int num)
{
	char	digit;
	int		count;
	int		ret;

	count = 0;
	if (num / 10 != 0)
	{
		ret = ft_putuint(num / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	digit = '0' + num % 10;
	ret = write(1, &digit, 1);
	if (ret == -1)
		return (ret);
	count++;
	return (count);
}

int	ft_puthex(unsigned long num, char *base)
{
	int	count;
	int	ret;

	count = 0;
	if (num / 16 != 0)
	{
		ret = ft_puthex(num / 16, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = write(1, &base[num % 16], 1);
	if (ret == -1)
		return (ret);
	count++;
	return (count);
}
