NAME = fractol

RM_DIR = rm -rf

CC = clang

DEBUG_FLAG = -g

OPT_FLAG = -O3

THREAD_FLAG = -pthread

CFLAGS = -Wall -Wextra -Werror $(THREAD_FLAG) $(DEBUG_FLAG) $(OPT_FLAG)

OLD_PROJ = projects

HEADER_1 = headers/ft_fractol.h

HEADER_2 = $(OLD_PROJ)/headers_2/ft_first_layer.h

DEPS = headers $(OLD_PROJ)/headers_2

OLD_PROJ_DIR = first_layer

SRCS_DIR = srcs

OBJ_DIR = obj

LIB_DIR = $(OLD_PROJ)/lib

LIB = $(OLD_PROJ_DIR).a

SRCS_FILES =	ft_main.c ft_valid_args.c ft_error_msg.c ft_init.c \
				ft_hooks_handler.c ft_draw.c ft_mandelbrot.c \
				ft_destroy_fractal.c ft_julia.c ft_burning_ship.c \
				ft_key_hooks.c ft_newton.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(MAKE) -C projects all 
	$(MAKE) -sC minilibx-linux all
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm $(LIB_DIR)/$(LIB)
	clear

clean:
	$(MAKE) -C projects clean
	$(MAKE) -sC minilibx-linux clean
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
	@echo "$(RED)Adding all changes..."
	sleep 1.5
	@clear
	@echo "$(GREEN)All changes added$(NC)"
	@read -p "Enter a custom commit message (leave blank to use the default message): " message; \
	if [ -n "$$message" ]; then \
		git commit -m "$$message"; \
	else \
		git commit -m "$(shell date +'%H:%M %d-%h') update"; \
	fi
	@echo "$(YELLOW)Committing...and..."
	git push
	@echo "$(GREEN)PUSHA KEKKO!$(NC)"

norm:
	norminette $(HEADER_1) $(SRCS_DIR) $(OLD_PROJ)

.PHONY: all clean fclean re push norm
.SILENT:
