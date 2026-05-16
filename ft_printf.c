/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 14:14:55 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char sp, va_list *args)
{
	if (sp == 'c')
		return (putarg_c(args));
	else if (sp == 's')
		return (putarg_s(args));
	else if (sp == 'p')
		return (putarg_p(args));
	else if (sp == 'd' || sp == 'i')
		return (putarg_di(args));
	else if (sp == 'u')
		return (putarg_u(args));
	else if (sp == 'x')
		return (putarg_x(args));
	else if (sp == 'X')
		return (putarg_X(args));
	else if (sp == '%')
		return (write(1, "%", 1));
	return (-1);
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
			count += handle_conversion(format[i], &args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int	n = 42;
	int	num_printf;
	// int	num_ft_printf;

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %c ***\n", 'c');
	printf("printf return: %d\n", num_printf);
	printf("\n*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %c ***\n", 'c');
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %s ***\n", "1234567890");
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %s ***\n", "1234567890");
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %p ***\n", &n);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %p ***\n", &n);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %d ***\n", 1234567890);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %d ***\n", 1234567890);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %i ***\n", 1234567890);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %i ***\n", 1234567890);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %u ***\n", 1234567890);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %u ***\n", 1234567890);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %x ***\n", 1234567890);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %x ***\n", 1234567890);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %X ***\n", 1234567890);
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %X ***\n", 1234567890);
	ft_printf("printf return: %d\n", num_printf);

	printf("========================================\n");
	printf("*** printf ***\n");
	num_printf = printf("*** Test: %% ***\n");
	printf("printf return: %d\n", num_printf);
	printf("*** ft_printf ***\n");
	num_printf = ft_printf("*** Test: %% ***\n");
	ft_printf("printf return: %d\n", num_printf);

// 	printf("========================================\n");
// 	printf("  Flag Tests: - + space # 0 . and width\n");
// 	printf("========================================\n\n");
// 
// 	/* ── 最小出力幅（field width）── */
// 	printf("--- Field Width ---\n");
// 	printf("[printf ] |%10d|\n",   42);
// 	ft_printf("[ft_printf] |%10d|\n",   42);
// 	printf("[printf ] |%10d|\n",  -42);
// 	ft_printf("[ft_printf] |%10d|\n",  -42);
// 	printf("\n");
// 
// 	/* ── '-' フラグ（左寄せ） ── */
// 	printf("--- '-' flag: left-align ---\n");
// 	printf("[printf ] |%-10d|\n",  42);
// 	ft_printf("[ft_printf] |%-10d|\n",  42);
// 	printf("[printf ] |%-10s|\n",  "hi");
// 	ft_printf("[ft_printf] |%-10s|\n",  "hi");
// 	printf("\n");
// 
// 	/* ── '+' フラグ（符号を常に表示） ── */
// 	printf("--- '+' flag: always show sign ---\n");
// 	printf("[printf ] |%+10d|\n",  42);
// 	ft_printf("[ft_printf] |%+10d|\n",  42);
// 	printf("[printf ] |%+10d|\n", -42);
// 	ft_printf("[ft_printf] |%+10d|\n", -42);
// 	printf("\n");
// 
// 	/* ── ' '（スペース）フラグ（正数の前にスペース） ── */
// 	printf("--- ' ' flag: space for positive ---\n");
// 	printf("[printf ] |% 10d|\n",  42);
// 	ft_printf("[ft_printf] |% 10d|\n",  42);
// 	printf("[printf ] |% 10d|\n", -42);
// 	ft_printf("[ft_printf] |% 10d|\n", -42);
// 	printf("\n");
// 
// 	/* ── '#' フラグ（代替形式：0x プレフィックス付き） ── */
// 	printf("--- '#' flag: alternate form (hex prefix) ---\n");
// 	printf("[printf ] |%#10x|\n",  255);
// 	ft_printf("[ft_printf] |%#10x|\n",  255);
// 	printf("[printf ] |%#10X|\n",  255);
// 	ft_printf("[ft_printf] |%#10X|\n",  255);
// 	printf("\n");
// 
// 	/* ── '0' フラグ（ゼロ埋め） ── */
// 	printf("--- '0' flag: zero-padding ---\n");
// 	printf("[printf ] |%010d|\n",  42);
// 	ft_printf("[ft_printf] |%010d|\n",  42);
// 	printf("[printf ] |%010d|\n", -42);
// 	ft_printf("[ft_printf] |%010d|\n", -42);
// 	printf("\n");
// 
// 	/* ── '.' 精度（文字列の最大文字数 / 数値の最小桁数） ── */
// 	printf("--- '.' precision: string truncation ---\n");
// 	printf("[printf ] |%.5s|\n",  "hello42");
// 	ft_printf("[ft_printf] |%.5s|\n",  "hello42");
// 	printf("--- '.' precision: min digits for integer ---\n");
// 	printf("[printf ] |%.8d|\n",  42);
// 	ft_printf("[ft_printf] |%.8d|\n",  42);
// 	printf("\n");
// 
// 	/* ── 優先順位テスト ── */
// 	printf("========================================\n");
// 	printf("  Priority Tests\n");
// 	printf("========================================\n\n");
// 
// 	/* '-' が '0' に勝る（左寄せ時はゼロ埋め無効） */
// 	printf("--- Priority: '-' overrides '0' ---\n");
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wformat"
// 	printf("[printf ] |%-010d|  <- '-' wins: left-align, no zero-pad\n",  42);
// #pragma GCC diagnostic pop
// 	ft_printf("[ft_printf] |%-010d|\n",  42);
// 	printf("\n");
// 
// 	/* '+' が ' '（スペース）に勝る */
// 	printf("--- Priority: '+' overrides ' ' (space) ---\n");
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wformat"
// 	printf("[printf ] |%+ 10d|  <- '+' wins: shows '+' not ' '\n",  42);
// #pragma GCC diagnostic pop
// 	ft_printf("[ft_printf] |%+ 10d|\n",  42);
// 	printf("\n");
// 
// 	/* width + precision の組み合わせ（文字列：precision が先に切り、width でパディング） */
// 	printf("--- Priority: precision truncates first, width pads after ---\n");
// 	printf("[printf ] |%10.3s|  <- truncate to 3 chars, then pad to width 10\n", "hello");
// 	ft_printf("[ft_printf] |%10.3s|\n", "hello");
// 	printf("\n");
// 
// 	/* precision が '0' より優先（precision=0 のとき 0 は出力されない） */
// 	printf("--- Priority: precision=0 suppresses zero output ---\n");
// #pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wformat"
// 	printf("[printf ] |%010.0d|  <- precision 0 with 0: no digit printed\n", 0);
// #pragma GCC diagnostic pop
// 	ft_printf("[ft_printf] |%010.0d|\n", 0);
// 	printf("\n");
// 
// 	/* '#' + width の組み合わせ（0x はwidthに含まれる） */
// 	printf("--- '#' with width: prefix counts toward width ---\n");
// 	printf("[printf ] |%#10x|  <- 0x + hex, total width 10\n", 255);
// 	ft_printf("[ft_printf] |%#10x|\n", 255);
// 	printf("\n");

	printf("|%.6s|\n", "-1234567");
	printf("|%.12d|\n", 123456789);

	return (0);
}
