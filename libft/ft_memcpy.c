/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:22:52 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/10 13:20:07 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	dest1[] = "bbbbb";
// 	char	dest2[] = "bbbbb";
// 	char	src[] = "aaaaa";
// 
// 	memcpy(dest1, src, 3);
// 	ft_memcpy(dest2, src, 3);
// 	printf("dest1: %s\n", dest1);
// 	printf("dest2: %s\n", dest2);
// 
// 	memcpy((void *)0, (void *)0, 3);
// 	ft_memcpy((void *)0, (void *)0, 3);
// 	printf("dest = (void *), src = (void *): %s\n", dest1);
// 	printf("dest = (void *), src = (void *): %s\n", dest2);
// }
