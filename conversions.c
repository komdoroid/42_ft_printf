/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:11:18 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 16:27:29 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg_c(va_list *args)
{
	char	c;
	int		ret;

	c = va_arg(*args, int);
	ret = write(1, &c, 1);
	return (ret);
}

int	putarg_s(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	putarg_p(va_list *args)
{
	unsigned long	ptr;
	void			*vptr;
	int				count;
	int				ret;

	count = 0;
	vptr = va_arg(*args, void *);
	if (vptr == NULL)
		return (ft_putstr("(nil)"));
	ptr = (unsigned long)vptr;
	ret = ft_putstr("0x");
	if (ret == -1)
		return (ret);
	count = ft_puthex(ptr, "0123456789abcdef");
	if (count == -1)
		return (count);
	return (ret + count);
}

int	putarg_di(va_list *args)
{
	int		decimal;
	char	*str;
	int		count;

	decimal = va_arg(*args, int);
	str = ft_itoa(decimal);
	if (str == NULL)
		return (-1);
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
