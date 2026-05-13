/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:25:41 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/07 20:58:41 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

// #include <string.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	*str = "Blue Giant";
// 
// 	printf("ft_strlen: %zu\n", ft_strlen(str));
// 	printf("strlen: %zu\n", strlen(str));
// }
