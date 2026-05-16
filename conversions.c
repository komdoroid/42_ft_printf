/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:11:18 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 14:12:02 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg_c(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return(write(1, &c, 1));
}

int	putarg_s(va_list *args)
{
	char	*str;

	str = va_arg(*args, char*);
	if (str == NULL)
		return (ft_putstr("(null)"));
	return(ft_putstr(str));
}

int	putarg_p(va_list *args)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = (unsigned long)va_arg(*args, void*);
	count += ft_putstr("0x");
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}

int	putarg_di(va_list *args)
{
	int		decimal;
	char	*str;
	int		count;

	decimal = va_arg(*args, int);
	str = ft_itoa(decimal);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	putarg_u(va_list *args)
{
	unsigned int	u_num;

	u_num = va_arg(*args, unsigned int);
	return (ft_putuint(u_num));
}

