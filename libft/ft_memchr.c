/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:44:08 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 13:11:16 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	const char	str[] = "42tokyo";
// 	char	c = 't';
// 	size_t	size = 2;
//
// 	printf("ft_memchr : %s\n", (char *)ft_memchr(str, c , size));
// 	printf("memchr : %s\n", (char *)memchr(str, c , size));
// }
//
