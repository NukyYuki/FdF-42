# Program
NAME = fdf

#	Compiler and Flags
CC			=	cc
CFLAGS		=	-fPIE -Wextra -Wall -Werror -g
INCLUDES	=	-I. -I./lib/minilibx-linux -I./lib/GNL -I./lib/libft
MLXFLAGS	=	-lXext -lX11 -lm

# Directories
MLXDIR		=	lib/minilibx-linux
GNLDIR		=	lib/GNL
LIBFTDIR	=	lib/libft

# Sources
SRCS	=	srcs/fdf.c \
			srcs/window/window.c \
			srcs/free_data/free_data.c \
			srcs/draw/lines.c \
			srcs/draw/lines_utils.c \
			srcs/draw/render.c \
			srcs/draw/projection.c \
			srcs/draw/color.c \
			srcs/draw/loop.c \
			srcs/map_parse/map.c \
			srcs/map_parse/map_utils.c \
			srcs/view/view.c \
			srcs/input/input.c \
			srcs/input/reset.c

OBJS	=	$(SRCS:.c=.o)

GNL_SRCS	=	$(GNLDIR)/get_next_line.c \
				$(GNLDIR)/get_next_line_utils.c
GNL_OBJS	=	$(GNL_SRCS:.c=.o)

# Libraries
MLX		=	$(MLXDIR)/libmlx.a
LIBFT	=	$(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	@make -C $(MLXDIR) --no-print-directory

$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(MLXDIR) clean --no-print-directory
	make -C $(LIBFTDIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
