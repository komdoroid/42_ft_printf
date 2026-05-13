/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:58:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 07:35:08 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// 
// void	to_upper_even(unsigned int num, char *c)
// {
// 	if (num % 2 == 0 && *c >= 'a' && *c <= 'z')
// 		*c = *c - 'a' + 'A';
// }
// 
// int	main(void)
// {
// 	char	str[] = "hello, 42tokyo";
// 
// 	ft_striteri(str, &to_upper_even);
// 	printf("to Upper : %s\n", str);
// }
