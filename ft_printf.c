/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/14 21:38:24 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

void	ft_putuint(unsigned int	num)
{
	char	digit;

	if (num / 10 != 0)
		ft_putuint(num / 10);
	digit = '0' + num % 10;
	write(1, &digit, 1);
}

void	ft_puthex(unsigned long num)
{
	char	hex[] = "0123456789abcdef";

	if (num / 16 != 0)
		ft_puthex(num / 16);
	write(1, &hex[num % 16], 1);
}

void	ft_putlhex(int num)
{
	char	hex[] = "0123456789abcdef";

	if (num / 16 != 0)
		ft_puthex(num / 16);
	write(1, &hex[num % 16], 1);
}

void	ft_putuhex(int	num)
{
	char	hex[] = "0123456789ABCDEF";

	if (num / 16 != 0)
		ft_putuhex(num / 16);
	write(1, &hex[num % 16], 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;
	char	c;
	unsigned long	ptr;
	char	*str;
	int		decimal;
	int		hexadecimal;
	unsigned int	u_int;

	va_start(args, format);
	i = 0;
	count = 0;
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
			else if (format[i] == 'p')
			{
				ptr = (unsigned long)va_arg(args, void*);
				ft_putstr("0x");
				ft_puthex(ptr);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				decimal = va_arg(args, int);
				ft_putstr(ft_itoa(decimal));
			}
			else if (format[i] == 'u')
			{
				u_int = va_arg(args, unsigned int);
				ft_putuint(u_int);
			}
			else if (format[i] == 'x')
			{
				hexadecimal = va_arg(args, int);
				ft_puthex(hexadecimal);
			}
			else if (format[i] == 'X')
			{
				hexadecimal = va_arg(args, int);
				ft_putuhex(hexadecimal);
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
			}
			else 
				return (count);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	return (i);
}


int	main(void)
{
	char	sample[] = "Hello, 42Tokyo!";
	int	n = 42;
	int	num_printf;
	int	num_ft_printf;

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
	printf("\n*** printf ***\n");
	num_printf = printf("c: %c , s: %s , %%: %% , i: %i, u: %u, p: %p, x: %x, X: %X.\n", 'X', "Hello,42 Tokyo", 1234, -1234, "memory_address", 1234, 1234);
	printf("printf return: %d\n", num_printf);
	printf("\n*** ft_printf ***\n");
	num_ft_printf = ft_printf("%c , %s , %% %i, u: %u, p: %p, x: %x, X: %X.\n", 'X', "Hello 42 Tokyo", 1234, -1234, "memory_address", 1234, 1234);
	printf("ft_printf return: %d\n", num_ft_printf);
}
