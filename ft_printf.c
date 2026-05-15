/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/14 22:45:10 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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

int	putarg_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return(write(1, &c, 1));
}

int	putarg_s(va_list args)
{
	char	*str;

	str = va_arg(args, char*);
	return(ft_putstr(str));
}

int	handle_conversion(char sp, va_list args)
{
	unsigned long	ptr;
	int		decimal;
	int		hexadecimal;
	unsigned int	u_int;

	if (sp == 'c')
		putarg_c(args);
	else if (sp == 's')
		putarg_s(args);
	else if (sp == 'p')
	{
		ptr = (unsigned long)va_arg(args, void*);
		ft_putstr("0x");
		ft_puthex(ptr);
	}
	else if (sp == 'd' || sp == 'i')
	{
		decimal = va_arg(args, int);
		ft_putstr(ft_itoa(decimal));
	}
	else if (sp == 'u')
	{
		u_int = va_arg(args, unsigned int);
		ft_putuint(u_int);
	}
	else if (sp == 'x')
	{
		hexadecimal = va_arg(args, int);
		ft_puthex(hexadecimal);
	}
	else if (sp == 'x')
	{
		hexadecimal = va_arg(args, int);
		ft_putuhex(hexadecimal);
	}
	else if (sp == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_conversion(format[i], args);
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}


int	main(void)
{
	char	sample[] = "hello, 42tokyo!";
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
	printf("*** %x ***\n", 255);
	printf("*** %% ***\n");
	printf("\n*** printf ***\n");
	num_printf = printf("c: %c , s: %s , %%: %% , i: %i, u: %u, p: %p, x: %x, x: %x.\n", 'x', "hello,42 tokyo", 1234, -1234, "memory_address", 1234, 1234);
	printf("printf return: %d\n", num_printf);
	printf("\n*** ft_printf ***\n");
	num_ft_printf = ft_printf("%c , %s , %% %i, u: %u, p: %p, x: %x, x: %x.\n", 'x', "hello 42 tokyo", 1234, -1234, "memory_address", 1234, 1234);
	printf("ft_printf return: %d\n", num_ft_printf);

	printf("========================================\n");
	printf("  Flag Tests: - + space # 0 . and width\n");
	printf("========================================\n\n");

	/* ── 最小出力幅（field width）── */
	printf("--- Field Width ---\n");
	printf("[printf ] |%10d|\n",   42);
	ft_printf("[ft_printf] |%10d|\n",   42);
	printf("[printf ] |%10d|\n",  -42);
	ft_printf("[ft_printf] |%10d|\n",  -42);
	printf("\n");

	/* ── '-' フラグ（左寄せ） ── */
	printf("--- '-' flag: left-align ---\n");
	printf("[printf ] |%-10d|\n",  42);
	ft_printf("[ft_printf] |%-10d|\n",  42);
	printf("[printf ] |%-10s|\n",  "hi");
	ft_printf("[ft_printf] |%-10s|\n",  "hi");
	printf("\n");

	/* ── '+' フラグ（符号を常に表示） ── */
	printf("--- '+' flag: always show sign ---\n");
	printf("[printf ] |%+10d|\n",  42);
	ft_printf("[ft_printf] |%+10d|\n",  42);
	printf("[printf ] |%+10d|\n", -42);
	ft_printf("[ft_printf] |%+10d|\n", -42);
	printf("\n");

	/* ── ' '（スペース）フラグ（正数の前にスペース） ── */
	printf("--- ' ' flag: space for positive ---\n");
	printf("[printf ] |% 10d|\n",  42);
	ft_printf("[ft_printf] |% 10d|\n",  42);
	printf("[printf ] |% 10d|\n", -42);
	ft_printf("[ft_printf] |% 10d|\n", -42);
	printf("\n");

	/* ── '#' フラグ（代替形式：0x プレフィックス付き） ── */
	printf("--- '#' flag: alternate form (hex prefix) ---\n");
	printf("[printf ] |%#10x|\n",  255);
	ft_printf("[ft_printf] |%#10x|\n",  255);
	printf("[printf ] |%#10X|\n",  255);
	ft_printf("[ft_printf] |%#10X|\n",  255);
	printf("\n");

	/* ── '0' フラグ（ゼロ埋め） ── */
	printf("--- '0' flag: zero-padding ---\n");
	printf("[printf ] |%010d|\n",  42);
	ft_printf("[ft_printf] |%010d|\n",  42);
	printf("[printf ] |%010d|\n", -42);
	ft_printf("[ft_printf] |%010d|\n", -42);
	printf("\n");

	/* ── '.' 精度（文字列の最大文字数 / 数値の最小桁数） ── */
	printf("--- '.' precision: string truncation ---\n");
	printf("[printf ] |%.5s|\n",  "hello42");
	ft_printf("[ft_printf] |%.5s|\n",  "hello42");
	printf("--- '.' precision: min digits for integer ---\n");
	printf("[printf ] |%.8d|\n",  42);
	ft_printf("[ft_printf] |%.8d|\n",  42);
	printf("\n");

	/* ── 優先順位テスト ── */
	printf("========================================\n");
	printf("  Priority Tests\n");
	printf("========================================\n\n");

	/* '-' が '0' に勝る（左寄せ時はゼロ埋め無効） */
	printf("--- Priority: '-' overrides '0' ---\n");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	printf("[printf ] |%-010d|  <- '-' wins: left-align, no zero-pad\n",  42);
#pragma GCC diagnostic pop
	ft_printf("[ft_printf] |%-010d|\n",  42);
	printf("\n");

	/* '+' が ' '（スペース）に勝る */
	printf("--- Priority: '+' overrides ' ' (space) ---\n");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	printf("[printf ] |%+ 10d|  <- '+' wins: shows '+' not ' '\n",  42);
#pragma GCC diagnostic pop
	ft_printf("[ft_printf] |%+ 10d|\n",  42);
	printf("\n");

	/* width + precision の組み合わせ（文字列：precision が先に切り、width でパディング） */
	printf("--- Priority: precision truncates first, width pads after ---\n");
	printf("[printf ] |%10.3s|  <- truncate to 3 chars, then pad to width 10\n", "hello");
	ft_printf("[ft_printf] |%10.3s|\n", "hello");
	printf("\n");

	/* precision が '0' より優先（precision=0 のとき 0 は出力されない） */
	printf("--- Priority: precision=0 suppresses zero output ---\n");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	printf("[printf ] |%010.0d|  <- precision 0 with 0: no digit printed\n", 0);
#pragma GCC diagnostic pop
	ft_printf("[ft_printf] |%010.0d|\n", 0);
	printf("\n");

	/* '#' + width の組み合わせ（0x はwidthに含まれる） */
	printf("--- '#' with width: prefix counts toward width ---\n");
	printf("[printf ] |%#10x|  <- 0x + hex, total width 10\n", 255);
	ft_printf("[ft_printf] |%#10x|\n", 255);
	printf("\n");

	return (0);
}
