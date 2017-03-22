/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:48 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 18:24:29 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include "str.h"

# define APPEND_CHAR(c)			str_append_char(&g_res, (c))
# define APPEND_CHAR_N(c, n)	str_append_char_n(&g_res, (c), (n))
# define APPEND_STRING(c)		str_append_string(&g_res, (c))
# define APPEND_STRING_N(c, n)	str_append_string_n(&g_res, (c), (n))

typedef struct	s_fmt
{
	bool	f_plus;
	bool	f_minus;
	bool	f_zero;
	bool	f_octo;
	bool	f_space;
	bool	has_width;
	int		width;
	bool	has_precision;
	int		precision;
	char	mod[3];
	char	type;
}				t_fmt;

t_str			g_res;

int				ft_printf(const char *format, ...);

const char		*parse(t_fmt *fmt, const char *f);
const char		*parse_flags(t_fmt *fmt, const char *f);
const char		*parse_width(t_fmt *fmt, const char *f);
const char		*parse_precision(t_fmt *fmt, const char *f);
const char		*parse_mod(t_fmt *fmt, const char *f);

#endif
