/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:43:17 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/25 08:09:06 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	int	c;
// 
// 	c =ft_isdigit('0');
// 	printf("ft_isdigi result: %d\n", c);
// 	c = isdigit('0');
// 	printf("isdigit result = %d\n", c);
// }
