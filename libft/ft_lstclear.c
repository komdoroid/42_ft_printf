/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:29:56 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 10:35:27 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		del(node->content);
		free(node);
		node = next_node;
	}
	*lst = NULL;
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
// void	delete_content(void *content)
// {
// 	free(content);
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
// 	ft_lstclear(&head, delete_content);
// 	print_list(head);
// 	if (head == NULL)
// 		printf("head is NULL (OK)\n");
// 	else
// 		printf("head is NOT NULL (NG)\n");
// 
// 	return (0);
// }
