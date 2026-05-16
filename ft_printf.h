/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 19:11:21 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/16 16:56:40 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		handle_conversion(char sp, va_list *args);
int		putarg_c(va_list *args);
int		putarg_s(va_list *args);
int		putarg_p(va_list *args);
int		putarg_di(va_list *args);
int		putarg_u(va_list *args);
int		putarg_x(va_list *args);
int		putarg_ux(va_list *args);
char	*ft_itoa(int num);
int		ft_putstr(char *str);
int		ft_putuint(unsigned int num);
int		ft_puthex(unsigned long num, char *base);

#endif
