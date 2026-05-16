/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:56:30 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 16:14:11 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen(long nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_fillnbr(char *res, long nb, int len)
{
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
}

char	*ft_itoa(int num)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = (long)num;
	len = ft_nbrlen(nb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_fillnbr(res, nb, len);
	return (res);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	printf("res: %s\n", ft_itoa(INT_MAX));
// 	printf("res: %s\n", ft_itoa(INT_MIN));
// 	printf("res: %s\n", ft_itoa(0));
// 	printf("res: %s\n", ft_itoa(1));
// 	printf("res: %s\n", ft_itoa(-1));
// }
