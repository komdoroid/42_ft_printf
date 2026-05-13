/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:30:20 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 13:33:16 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// 
// void	print_list(t_list *lst)
// {
// 	while (lst != NULL)
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
// 	t_list	*node1 = ft_lstnew("A");
// 	t_list	*node2 = ft_lstnew("B");
// 	t_list	*node3 = ft_lstnew("C");
// 
// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);
// 
// 	t_list	*res = ft_lstlast(head);
// 	print_list(head);
// 	printf("res->content: %s\n", (char *)res->content);
// 
// 	return (0);
// }
