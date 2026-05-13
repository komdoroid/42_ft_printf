/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:36:02 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 10:37:14 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}

// #include <stdio.h>
// 
// void	print_list(t_list *lst)
// {
// 	if (!lst)
// 		return ;
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// 
// void	to_upper(void *content)
// {
// 	if (!content)
// 		return ;
// 	char	*str = (char *)content;
// 	int	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	return ;
// }
// 
// int	main(void)
// {
// 	t_list	*head = NULL;
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;
// 
// 	str1 = (char *)malloc(sizeof(char) * 10);
// 	str2 = (char *)malloc(sizeof(char) * 10);
// 	str3 = (char *)malloc(sizeof(char) * 10);
// 	ft_strlcpy(str1, "Hello, ", 10);
// 	ft_strlcpy(str2, "42 ", 10);
// 	ft_strlcpy(str3, "Tokyo.", 10);
// 
// 	t_list	*node1 = ft_lstnew(str1);
// 	t_list	*node2 = ft_lstnew(str2);
// 	t_list	*node3 = ft_lstnew(str3);
// 
// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);
// 
// 	print_list(head);
// 	ft_lstiter(head, to_upper);
// 	print_list(head);
// 	return (0);
// }
