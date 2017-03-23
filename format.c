/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:30:12 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/23 16:42:15 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_fmt(t_fmt *fmt, va_list ap)
{
	if (IS_CHAR(fmt))
		format_char(fmt, ap);
	else if (IS_WSTRING(fmt))
		format_wstring(fmt, ap);
	else if (IS_STRING(fmt))
		format_string(fmt, ap);
	else if (IS_DECIMAL(fmt) || IS_UNSIGNED(fmt))
		format_number_decimal(fmt, ap);
	// TODO: Format hexadecimals, octals
	else if (fmt->type != '\0')
		format_unknown(fmt);
}
