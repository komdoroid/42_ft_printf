/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:41:40 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/28 21:44:11 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	head = 0;
	tail = ft_strlen(s1);
	while (head < tail && ft_strchr(set, s1[head]))
		head++;
	while (tail > head && ft_strchr(set, s1[tail - 1]))
		tail--;
	trim = (char *)malloc(tail - head + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + head, tail - head + 1);
	return (trim);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	s1[] = "marumarumorimori";
// 	char	set[] = "mari";
// 	char	*res;
// 
// 	res = ft_strtrim(s1, set);
// 	if (res == NULL)
// 		return (1);
// 	printf("result : %s\n", res);
// }
