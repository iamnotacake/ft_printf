/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 18:51:45 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str			g_res;

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;
	int			res;

	va_start(ap, format);
	str_init(&g_res);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format);
			format_fmt(&fmt, ap);
		}
		else
			APPEND_CHAR(*(format++));
	}
	va_end(ap);
	write(1, g_res.string, g_res.length);
	res = g_res.length;
	str_free(&g_res);
	return (res);
}
