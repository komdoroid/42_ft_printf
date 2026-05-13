/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:05:13 by kkomurat          #+#    #+#             */
/*   Updated: 2026/04/26 10:29:36 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>
// 
// void	del_content(void *content)
// {
// 	free(content);
// }
// 
// void	print_list(t_list *lst)
// {
// 	if (!lst)
// 		return ;
// 	while (lst)
// 	{
// 		printf("%s ->", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// 
// int	main(void)
// {
// 	char	source1[] = "Hello ";
// 	char	source2[] = "World !";
// 
// 	char	*str1 = (char *)malloc(10);
// 	if (!str1)
// 		return (1);
// 	char	*str2 = (char *)malloc(10);
// 	if (!str2)
// 		return (1);
// 	ft_strlcpy(str1, source1, ft_strlen(source1));
// 	ft_strlcpy(str2, source2, ft_strlen(source2));
// 
// 	t_list	*head = ft_lstnew((void *)str1);
// 	t_list	*node1 = ft_lstnew((void *)str2);
// 
// 	ft_lstadd_back(&head, node1);
// 	print_list(head);
// 	ft_lstdelone(head->next, del_content);
// 	// print_list(head);
// }
