/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:40:50 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/08 20:53:18 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **res, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	*make_word(char const *s, size_t start, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[start + len] != '\0' && s[start + len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static bool	make_res(char **res, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[j] = make_word(s, i, c);
			if (res[j] == NULL)
			{
				free_split(res, j);
				return (false);
			}
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		num_words;

	if (s == NULL)
		return (NULL);
	num_words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (res == NULL)
		return (NULL);
	if (!make_res(res, s, c))
		return (NULL);
	res[num_words] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	s[] = "as;ldhflkask;jio ;a;lskaaa";
// 	char	c;
// 	char	**res;
// 	int		i;
// 	int		j;
// 
// 	c = 'a';
// 	res = ft_split(s, c);
// 	i = 0;
// 	while (res[i] != NULL)
// 	{
// 		j = 0;
// 		while (res[i][j] != '\0')
// 		{
// 			write(1, &res[i][j], 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }
