#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 10:09:09 by nsimonov          #+#    #+#              #
#    Updated: 2017/03/05 21:17:09 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC =   filler.c \
		libft/get_next_line.c \
		libft/ft_putchar_fd.c \
		libft/ft_strchr.c \
		libft/ft_atoi.c \
		libft/ft_putstr_fd.c \
		libft/ft_strlen.c \
		libft/ft_strstr.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strnew.c \
		libft/ft_memset.c \
		libft/ft_strncmp.c \
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



all: comp

comp:
	gcc -o filler $(SRC) libft/libft.a -Wall -Wextra -Werror

clean:
	@rm -f a.out
	@echo "Object files of library has been deleted (clean rule)."

fclean: clean
	@rm -f a.out
	@echo "Library has been deleted (fclean rule)."

re: fclean all
