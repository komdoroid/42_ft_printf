/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:10:21 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/25 08:41:03 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (i < size - dst_len - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>
// 
// int	main(void)
// {
// 	char	dst1[10] = "Hi";
// 	char	dst2[10] = "Hi";
// 	char	src[] = "42tokyo";
// 	size_t	size = 1;
// 
// 	printf("ft_strlcat : %zu\n", ft_strlcat(dst1, src, size));
// 	printf("dst1 : %s\n", dst1);
// 	printf("ft_strlcat : %zu\n", ft_strlcat(dst2, src, size));
// 	printf("dst2 : %s\n", dst2);
// }
// 
