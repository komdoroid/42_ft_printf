/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:31:14 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/07 22:02:46 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c)
{
	if (9 <= c && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

static int	calc_result(const char *str, int i, int sign)
{
	long	res;

	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (res > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)sign * res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	return (calc_result(nptr, i, sign));
}

// #include <stdlib.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	char	str[] = "     +123456789012345";
//
// 	printf("ft_atoi : %d\n", ft_atoi(str));
// 	printf("atoi : %d\n", atoi(str));
// }