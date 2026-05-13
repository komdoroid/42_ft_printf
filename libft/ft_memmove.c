/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:33:13 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 20:54:39 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (0 < i)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t	i;
// 	unsigned char	*tmp;
// 	unsigned char	*d;
// 	const unsigned char	*s;
//
// 	d = (unsigned char *)dest;
// 	s = (const unsigned char *)src;
// 	i = 0;
// 	tmp = (unsigned char *)malloc(sizeof(unsigned char) * n);
// 	if (tmp == NULL)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		tmp[i]  = s[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		d[i] = tmp[i];
// 		i++;
// 	}
// 	free(tmp);
// 	return (dest);
// }
//
// #include <stdio.h>
//
// int	main(void)
// {
// 	char	dest[] = "12345";
// 	char	src[] = "67890";
//
// 	ft_memmove(dest, src, 3);
// 	printf("dest: %s\n", dest);
// }
