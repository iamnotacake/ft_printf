/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:30:12 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 19:23:53 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_fmt(t_fmt *fmt, va_list ap)
{
	if (IS_CHAR(fmt->type))
		format_char(fmt, ap);
	else if (IS_STRING(fmt->type))
		format_string(fmt, ap);
	// TODO: Format numbers
	else if (fmt->type != '\0')
		format_unknown(fmt);
}
