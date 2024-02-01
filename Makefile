# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 16:12:56 by atudor            #+#    #+#              #
#    Updated: 2024/01/14 16:13:05 by atudor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -Ofast
RM			= rm -f

SRCS_DIR	= srcs/
GNL_DIR		= inc/gnl/
MLX_DIR		= mlx/
FILES		= main ft_atoi_base init parse_map draw_map rendering  
GNL_FILES	= $(addprefix $(GNL_DIR), get_next_line.c get_next_line_utils.c)

MLX_HEADER	= mlx/
HEADER		= inc/
INCLUDE		= -I$(HEADER) -I$(MLX_HEADER) -I$(LIB_H)

SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES))) $(GNL_FILES)
OBJS		= $(SRCS:.c=.o)
MINILIB		= mlx/
LIB_H		= libft/
LIBFT_DIR	= libft

%.o:	%.c $(HEADER)fdf.h $(MLX_HEADER)mlx.h $(LIB_H)libft.h Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: libft.a libmlx.a ${OBJS}
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS} $(INCLUDE) -L $(MLX_DIR) -lmlx -L $(LIBFT_DIR) -lft -lm -framework AppKit -framework OpenGL

libmlx.a:
	$(MAKE) -C $(MLX_DIR)

libft.a:
	$(MAKE) -C $(LIBFT_DIR)

all:
	$(MAKE) $(NAME)

clean:
	${RM} $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIB) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIB) clean

re:			fclean all

.PHONY:		all clean fclean re libmlx.a libft.a





