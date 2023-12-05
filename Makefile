# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:34:02 by ner-roui          #+#    #+#              #
#    Updated: 2023/12/02 13:19:00 by ner-roui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCF = 	ft_printf.c\
		ft_printf_pointer.c \
		ft_printf_unsigned.c \
		ft_putstr.c \
		ft_printf_int.c \
		ft_putchar.c \
		ft_printf_hex.c\
		ft_printf_H.c
	
OBJF = $(SRCF:.c=.o)

all: $(NAME)

RM = rm -f

all: $(NAME)

$(NAME):$(OBJF)
	ar -rc $(NAME) $(OBJF)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJF) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY:  clean 

