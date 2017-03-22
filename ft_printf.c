/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:39:32 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_fmt		fmt;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = parse(&fmt, ++format);
			// TODO: Print according to format
		}
		else
		{
			format++; // TODO: Append current char to result string
		}
	}
	va_end(ap);
	return (0); // TODO: Print string and return length
}
