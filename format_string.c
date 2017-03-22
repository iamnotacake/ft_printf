/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:22:42 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:34:45 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_string(t_fmt *fmt, va_list ap)
{
	char		*string;
	int			len;

	string = va_arg(ap, char *);
	string = string ?: "(null)";
	len = STRLEN(string);
	if (fmt->has_precision && fmt->precision < len)
		len = fmt->precision;
	if (fmt->has_width && fmt->width > len && !fmt->f_minus)
		APPEND_CHAR_N(fmt->f_zero ? '0' : ' ', fmt->width - len);
	APPEND_STRING_N(string, len);
	if (fmt->has_width && fmt->width > len && fmt->f_minus)
		APPEND_CHAR_N(' ', fmt->width - len);
}
