# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keitabe <keitabe@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 17:09:03 by keitabe           #+#    #+#              #
#    Updated: 2025/12/05 17:46:41 by keitabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libftprintf.a

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I. -I..
AR      := ar
ARFLAGS := rcs
RM      := rm -f

SRCS    := \
	ft_printf.c \
	ft_spec_char.c \
	ft_spec_hex.c \
	ft_spec_num.c \
	ft_spec_string_ptr.c

OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c ft_printf.h ../libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
