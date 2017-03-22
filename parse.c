/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:21:40 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:28:32 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		*parse(t_fmt *fmt, const char *f)
{
	const char	*old;

	BZERO(fmt, sizeof(t_fmt));
	while (true)
	{
		old = f;
		f = parse_flags(fmt, f);
		f = parse_width(fmt, f);
		f = parse_precision(fmt, f);
		f = parse_mod(fmt, f);
		if (old == f)
			break ;
	}
	fmt->type = *(f++);
	return (f);
}
