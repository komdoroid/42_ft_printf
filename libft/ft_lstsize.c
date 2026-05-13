/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:57:05 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 09:58:49 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	t_list	*head = NULL;
// 
// 	t_list	*node1 = ft_lstnew("A");
// 	t_list	*node2 = ft_lstnew("B");
// 	t_list	*node3 = ft_lstnew("C");
// 	t_list	*node4 = ft_lstnew("D");
// 
// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);
// 	ft_lstadd_front(&head, node4);
// 
// 	int	res = ft_lstsize(head);
// 	printf("int = %d\n", res);
// 
// 	return (0);
// }
