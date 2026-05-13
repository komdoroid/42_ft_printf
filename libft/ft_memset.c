/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:15:47 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 14:47:18 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
//
// 	str1 = (char *)malloc(sizeof(char) * 10);
// 	if (!str1)
// 		return (1);
// 	str1 = (char *)ft_memset((void *)str1, 'A', 10);
// 	str1[10] = '\0';
//
// 	str2 = (char *)malloc(sizeof(char) * 10);
// 	if (!str2)
// 		return (1);
// 	str2 = (char *)memset((void *)str2, 'A', 10);
// 	str2[10] = '\0';
// 	printf("ft_memset : %s\n", str1);
// 	printf("memset    : %s\n", str2);
// 	free(str1);
// 	free(str2);
// }