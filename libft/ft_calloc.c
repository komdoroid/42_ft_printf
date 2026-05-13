/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:50:49 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 18:50:13 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	ptr = NULL;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	size_t	nmemb = 10;
// 	size_t	size = 4;
// 	size_t	i = 0;
// 	void	*res;
// 	unsigned char	*p;
//
// 	res = ft_calloc(nmemb, size);
// 	p = (unsigned char *)res;
// 	while (i < nmemb * size)
// 	{
// 		printf("%d\n", p[i]);
// 		i++;
// 	}
// }
