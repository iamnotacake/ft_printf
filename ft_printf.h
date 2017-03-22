/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:46:48 by alischyn          #+#    #+#             */
/*   Updated: 2017/03/22 17:31:53 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdbool.h>
# include <stdarg.h>

# define STRNCMP(a, b, n) __builtin_strncmp(a, b, n)
# define STRCPY(a, b) __builtin_strcpy(a, b)
# define BZERO(a, n) __builtin_bzero(a, n)

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

int				ft_printf(const char *format, ...);

const char		*parse(t_fmt *fmt, const char *f);
const char		*parse_flags(t_fmt *fmt, const char *f);
const char		*parse_width(t_fmt *fmt, const char *f);
const char		*parse_precision(t_fmt *fmt, const char *f);
const char		*parse_mod(t_fmt *fmt, const char *f);

#endif
