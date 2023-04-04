NAME = first_layer.a

ARCL = ar -crs

RM = rm -f

SRCS = ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c \
	ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
	ft_memchr.c ft_calloc.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_strncmp.c \
	ft_atoi.c ft_isdigit.c ft_strjoin.c ft_itoa.c ft_substr.c ft_strtrim.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_strmapi.c ft_striteri.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_get_next_line.c ft_get_next_line_utils.c ft_get_next_line_bonus.c ft_get_next_line_utils_bonus.c \
	ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_u_nbr.c ft_print_hex.c \
	ft_print_ptr.c ft_printf.c ft_atof.c \

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(ARCL) $(NAME) $(OBJ)
	clear

clean:
	$(RM) $(OBJ)
	clear

fclean: clean
	$(RM) $(NAME)
	clear

re: fclean all
	clear

norm:
	norminette *

.PHONY: all clean fclean re
.SILENT:
