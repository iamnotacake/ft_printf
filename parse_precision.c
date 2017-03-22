/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:11:51 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:12:42 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse_precision(t_fmt *fmt, const char *f)
{
	if (*f == '.' && f++)
	{
		fmt->has_precision = true;
		fmt->precision = 0;
		while ('0' <= *f && *f <= '9')
			fmt->precision = fmt->precision * 10 + *(f++) - '0';
	}
	return (f);
}
