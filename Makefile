# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 16:43:25 by alischyn          #+#    #+#              #
#    Updated: 2017/03/22 19:24:37 by alischyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -g
SOURCES = ft_printf.c \
		  parse.c parse_flags.c parse_width.c parse_precision.c parse_mod.c \
		  str_alloc.c str_append_char.c str_append_string.c \
		  format.c format_char.c format_string.c format_unknown.c
OBJECTS = $(addprefix obj/,$(subst .c,.o,$(SOURCES)))
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -cru $@ $^

obj/%.o: %.c *.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj

fclean:
	rm -rf obj $(NAME)

re: fclean all

norm:
	norminette *.c *.h

test: all
	$(CC) test.c $(NAME) -o test
