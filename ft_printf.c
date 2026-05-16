/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:07 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 17:01:30 by kkomurat         ###   ########.fr       */
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
		return (putarg_ux(args));
	else if (sp == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;
	size_t	i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ret = handle_conversion(format[++i], &args);
		else
			ret = write(1, &format[i], 1);
		if (ret == -1)
		{
			va_end(args);
			return (ret);
		}
		count += ret;
		i++;
	}
	va_end(args);
	return (count);
}
