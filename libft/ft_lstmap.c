/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:42:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/10 16:42:20 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	create_new_node(t_list **new_list, t_list *node, void *content)
{
	node->content = content;
	node->next = NULL;
	ft_lstadd_back(new_list, node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		content = f(lst->content);
		create_new_node(&new_list, node, content);
		lst = lst->next;
	}
	return (new_list);
}

// #include <stdio.h>
// 
// void	delete_content(void *content)
// {
// 	free(content);
// }
// 
// void	*to_upper(void *content)
// {
// 	if (!content)
// 		return (NULL);
// 	char	*str = (char *)content;
// 	int	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	return ((void *)str);
// }
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
// int	main(void)
// {
// 	t_list	*head = NULL;
// 
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
// 	t_list	*new = ft_lstmap(head, to_upper, delete_content);
// 	printf("Original List: ");
// 	print_list(head);
// 	printf("New List     : ");
// 	print_list(new);
// }
