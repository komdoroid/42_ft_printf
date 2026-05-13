/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:01:38 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/09 14:46:38 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		last = (char *)&s[i];
	return (last);
}

// #include <unistd.h>
// 
// int	main(void)
// {
// 	char	*str = "42tokyo";
// 	char	*res;
// 
// 	res = ft_strrchr(str, 'o');
// 	while (*res != '\0')
// 	{
// 		write(1, res, 1);
// 		res++;
// 	}
// 	write(1, "\n", 1);
// }
