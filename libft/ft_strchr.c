/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:50:25 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/07 21:54:47 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <unistd.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*str = "42tokyo";
// 	char	*res;
//
// 	res = ft_strchr(str, 'o');
// 	while (*res != '\0')
// 	{
// 		write(1, res, 1);
// 		res++;
// 	}
// 	write(1, "\n", 1);
// }
