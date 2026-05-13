/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:09:25 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/09 15:05:53 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	str1[] = "42tokyo";
// 	char	str2[] = "43tokyo";
// 	size_t	size = 4;
// 
// 	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, size));
// 	printf("strncmp : %d\n", strncmp(str1, str2, size));
// }
