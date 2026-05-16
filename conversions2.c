/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:12:37 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 16:54:29 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putarg_x(va_list *args)
{
	unsigned int	hexadecimal;

	hexadecimal = va_arg(*args, unsigned int);
	return (ft_puthex(hexadecimal, "0123456789abcdef"));
}

int	putarg_ux(va_list *args)
{
	unsigned int	hexadecimal;

	hexadecimal = va_arg(*args, unsigned int);
	return (ft_puthex(hexadecimal, "0123456789ABCDEF"));
}
