/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/13 21:43:17 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	char	*str;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			str = va_arg(args, char*);
			putstr(str);
			// check identifier
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	char	sample[] = "Hello, 42Tokyo!";
	int	n = 42;

	printf("sample1\n");
	printf("*** %c ***\n", '4');
	printf("*** %s ***\n", sample);
	printf("*** %p ***\n", &n);
	printf("*** %d ***\n", 42);
	printf("*** %i ***\n", 42);
	printf("*** %u ***\n", 42);
	printf("*** %u ***\n", -1);
	printf("*** %x ***\n", 255);
	printf("*** %X ***\n", 255);
	printf("*** %% ***\n");
	printf("\n*** ft_printf ***\n");
	ft_printf("% % %\n", "Hello", "42", "Tokyo");
}
