/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:37:33 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 09:56:40 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// 
// void	print_list(t_list *lst)
// {
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
// 	ft_lstadd_front(&head, node1);
// 	print_list(head);
// 
// 	ft_lstadd_front(&head, node2);
// 	print_list(head);
// 
// 	ft_lstadd_front(&head, node3);
// 	print_list(head);
// 
// 	return (0);
// }
