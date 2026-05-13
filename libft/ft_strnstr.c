/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:11:15 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 14:51:26 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] != '\0' && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	big[] = "Hello, 42tokyo";
// 	char	little[] = "yoyo";
// 	char	*res;
//
// 	res = ft_strnstr(big, little, 15);
// 	if (res == NULL)
// 	{
// 		write(1, "Not found\n", 10);
// 		return (0);
// 	}
// 	while (*res != '\0')
// 	{
// 		write(1, res, 1);
// 		res++;
// 	}
// 	write(1, "\n", 1);
// }
