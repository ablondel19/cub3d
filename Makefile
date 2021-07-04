# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 12:20:37 by ablondel          #+#    #+#              #
#    Updated: 2021/02/14 12:43:45 by ablondel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC = ft_bmp_utils.c \
ft_bmp.c \
ft_mlx_exit.c \
ft_mp_add_ceiling_rgb.c \
ft_mp_add_east_tex.c \
ft_mp_add_floor_rgb.c \
ft_mp_add_north_tex.c \
ft_mp_add_res.c \
ft_mp_add_south_tex.c \
ft_mp_add_sprite_tex.c \
ft_mp_add_utils.c \
ft_mp_add_west_tex.c \
ft_mp_all_infos.c \
ft_mp_atoi.c \
ft_mp_exit_all.c \
ft_mp_gnl_utils.c \
ft_mp_gnl.c \
ft_mp_init_struct.c \
ft_mp_launcher_utils.c \
ft_mp_launcher.c \
ft_mp_lst.c \
ft_mp_partcmp.c \
ft_mp_playable_utils.c \
ft_mp_playable.c \
ft_raycast_utils_2.c \
ft_rc_cub3d.c \
ft_rc_draw.c \
ft_rc_init_utils.c \
ft_rc_init.c \
ft_rc_move.c \
ft_rc_raycast_2.c \
ft_rc_raycast_utils.c \
ft_rc_raycast.c \
ft_rc_save_bmp.c \
ft_rc_sprite_utils.c \
ft_rc_utils.c

OBJ = ${SRC:.c=.o}

NAME = cub3D

$(NAME):		$(OBJ)
		$(CC) -lmlx -framework AppKit -framework OpenGL libmlx.a $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re