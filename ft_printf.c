/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/13 23:33:08 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
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
	char	c;
	char	*str;
	int		decimal;
	unsigned int	u_int;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char*);
				ft_putstr(str);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				decimal = va_arg(args, int);
				ft_putstr(ft_itoa(decimal));
			}
			else if (format[i] == 'u')
			{
				u_int = va_arg(args, unsigned int);
				ft_putstr(ft_itoa(decimal));
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
			}
			else 
				return (0);
		}
		else
			write(1, &format[i], 1);
		i++;
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
	printf("c: %c , s: %s , %%: %% , i: %i, u: %u.\n", 'X', "Hello,42 Tokyo", 1234, -1234);
	printf("\n*** ft_printf ***\n");
	ft_printf("%c , %s , %% %i, u: %u.\n", 'X', "Hello 42 Tokyo", 1234, -1234);
}
