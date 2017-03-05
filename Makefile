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
		analyze_fig.c \
		libft/ft_strlen.c \
		libft/ft_strstr.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strnew.c \
		libft/ft_memset.c \
		libft/ft_strncmp.c \
		ft_pow.c \
		ft_sqrt.c \
		write_coor_in_lst.c \
		select_short_way_tocenr.c \
		rebuild_myfig.c \
		check_put.c \
		take_cor_where_to_put.c \
		put_my_fig.c \
		get_player.c \
		get_map_size.c \
		take_figure_size.c \
		take_cordin_myplayer.c \
		struct_init.c \
		short_way_to_diagA.c \
		short_way_to_diagB.c \
		reset_all_value.c



all: comp

comp:
	gcc $(SRC) libft/libft.a

clean:
	@rm -f a.out
	@echo "Object files of library has been deleted (clean rule)."

fclean: clean
	@rm -f a.out
	@echo "Library has been deleted (fclean rule)."

re: fclean all
