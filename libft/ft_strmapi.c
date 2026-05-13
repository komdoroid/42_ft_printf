/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:06:13 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 14:52:19 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
//
// char	to_upper_even(unsigned int num, char c)
// {
// 	if (num % 2 == 0 && c >= 'a' && c <= 'z')
// 		return (c - 'a' + 'A');
// 	return (c);
// }
//
// int	main(void)
// {
// 	char const	str[] = "Hello, 42tokyo!";
// 	printf("toupper : %s\n", ft_strmapi(str, &to_upper_even));
// }
