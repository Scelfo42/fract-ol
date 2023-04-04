NAME = fractol

RM_DIR = rm -rf

CC = clang

DEBUG_FLAG = -g

OPT_FLAG = -O3

CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG) $(OPT_FLAG)

OLD_PROJ = projects

HEADER_1 = headers/ft_fractol.h

HEADER_2 = $(OLD_PROJ)/headers_2/ft_first_layer.h

DEPS = headers $(OLD_PROJ)/headers_2

OLD_PROJ_DIR = first_layer

SRCS_DIR = srcs

OBJ_DIR = obj

LIB_DIR = $(OLD_PROJ)/lib

LIB = $(OLD_PROJ_DIR).a

SRCS_FILES = ft_main.c ft_valid_args.c ft_error_msg.c ft_init.c ft_hooks_handler.c ft_draw.c ft_mandelbrot.c ft_destroy_fractal.c ft_julia.c ft_burning_ship.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(MAKE) -C projects all 
	$(MAKE) -C minilibx-linux all
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIB_DIR)/$(LIB)
	clear

clean:
	$(MAKE) -C projects clean
	$(MAKE) -C minilibx-linux clean
	$(RM_DIR) $(OBJ_DIR)/
	$(RM) $(O_SRCS)
	clear

fclean: clean 
	$(RM_DIR) $(LIB_DIR)
	$(RM) $(NAME)
	clear

re: fclean all
	clear

push: 
	git add .
	git commit -m "March update"
	git push
	clear

norm:
	norminette $(HEADER_1) $(SRCS_DIR) $(OLD_PROJ)

.PHONY: all clean fclean re push norm
.SILENT:
