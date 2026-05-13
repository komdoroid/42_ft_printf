/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:27:36 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 14:51:46 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
	return ;
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	str[] = "Hello, 42tokyo";
// 	int	i = 0;
//
// 	ft_bzero(str, 5);
// 	while (i < 13)
// 	{
// 		printf("result : %c\n", str[i]);
// 		i++;
// 	}
// }
