/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:41:29 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/25 08:50:12 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	c = 'A';
// 
// 	printf("c : %c\n", ft_toupper(c));
// }
