/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:05:51 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 14:50:23 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 31 || 127 <= c)
		return (0);
	return (1);
}

// #include <stdio.h>
// #include <ctype.h>
//
// int	main(void)
// {
// 	// char	c = '\t';
// 	char	c = 'A';
//
// 	printf("ft_isprint: %d\n", ft_isprint(c));
// 	printf("isprint: %d\n", isprint(c));
// }
