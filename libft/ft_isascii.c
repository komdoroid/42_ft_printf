/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:57:57 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/23 22:16:03 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c < 0x80)
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
// 	c =ft_isascii(50);
// 	printf("ft_isascii result: %d\n", c);
// 	c = isascii(50);
// 	printf("isascii result = %d\n", c);
// }
