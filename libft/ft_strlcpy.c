/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:35:48 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/28 21:03:15 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>
// 
// int	main(void)
// {
// 	char	dst1[10];
// 	char	dst2[10];
// 	char	src[] = "42tokyo";
// 	size_t	size = 5;
// 
// 	printf("ft_strlcpy : %zu\n", ft_strlcpy(dst1, src, size));
// 	printf("dst1 : %s\n", dst1);
// 	printf("strlcpy : %zu\n", strlcpy(dst2, src, size));
// 	printf("dst2 : %s\n", dst2);
// }
