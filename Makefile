#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 10:09:09 by nsimonov          #+#    #+#              #
#    Updated: 2017/03/11 14:43:16 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

SRC =   filler.c \
		ft_putchar_fd.c \
		get_next_line.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_putnbr_fd.c \
		ft_strnew.c \
		ft_memset.c \
		ft_strncmp.c \
		ft_memdel.c \
		write_coor_in_lst.c \
		check_put.c \
		take_cor_where_to_put.c \
		put_my_fig.c \
		get_player.c \
		get_map_size.c \
		take_figure_size.c \
		take_cordin_myplayer.c \
		reset_all_value.c \
		copy_map.c \
		choose_way.c \
		work_with_fig.c \
		struct_init.c \
		copy_figure.c \
		math.c \
		close_side.c

OBJ = $(SRC:.c=.o)

HEADER = filler.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all