/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:30:10 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 09:32:26 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	content[] = "42 Tokyo";
// 	t_list	*res;
// 
// 	res = ft_lstnew(content);
// 	printf("content: %s\n", (char *)res->content);
// 
// 	printf("node address: %p\n", (void *)res);
// 	printf("content address: %p\n", res->content);
// 
// 	free(res);
// }
