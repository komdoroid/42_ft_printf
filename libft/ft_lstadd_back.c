/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:59:05 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 10:03:22 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tail = *lst;
	while (tail->next)
		tail = tail->next;
	tail->next = new;
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
// int	main(void)
// {
// 	t_list	*head = NULL;
// 
// 	t_list	*node1 = ft_lstnew("A");
// 	t_list	*node2 = ft_lstnew("B");
// 	t_list	*node3 = ft_lstnew("C");
// 
// 	ft_lstadd_back(&head, node1);
// 	print_list(head);
// 	ft_lstadd_back(&head, node2);
// 	print_list(head);
// 	ft_lstadd_back(&head, node3);
// 	print_list(head);
// 
// 	return(0);
// }
