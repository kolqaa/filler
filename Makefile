#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 10:09:09 by nsimonov          #+#    #+#              #
#    Updated: 2017/02/24 12:58:57 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler.a

SRC =   filler.c
        libft/ft_putchar_fd.c
        libft/get_next_line.c
        libft/ft_putchar_fd.c
        libft/ft_strchr.c
        libft/ft_atoi.c
        libft/ft_putstr_fd.c
        libft/ft_strlen.c
        libft/ft_strstr.c
        libft/ft_putnbr_fd.c
        libft/ft_strnew.c
        libft/ft_memset.c
        libft/ft_strncmp.c
        ft_pow.c
        ft_sqrt.c
        write_coor_in_lst.c
        select_short_way_tocenr.c
        fig_to_my_player.c
        check_put.c
        to_put_coordin.c
        put_my_fig.c
        get_player.c
        get_map_size.c
        take_figure_size.c
        take_cordin_myplayer.c
        struct_init.c
        reset_all_value.c)

OBJ = $(SRC:.c=.o)

HEADER = filler.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library $(NAME) has been compiled (all rule)."

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "Object files of library has been deleted (clean rule)."

fclean: clean
	@rm -f $(NAME)
	@echo "Library has been deleted (fclean rule)."

re: fclean all
