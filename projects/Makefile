# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:26:28 by cscelfo           #+#    #+#              #
#    Updated: 2023/04/03 18:49:37 by cscelfo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = projects

LIB = first_layer.a

DIR = first_layer

LIB_DIR = lib

RM = rm -f

RMDIR = rm -rf

HEADER = headers_2

RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m

all: $(NAME)

$(NAME): dir check_mandatory
	$(MAKE) -C $(DIR)
	mv -u $(DIR)/$(LIB) $(LIB_DIR)
	clear

dir:
	if [ -d "$(DIR)" ]; then \
		echo "$(GREEN)PERFECT! $(BLUE)$(DIR) $(GREEN)exists!"; \
	else \
		echo "$(RED)ERROR! $(DIR) doesn't exist"; \
	fi
	mkdir -p $(LIB_DIR)

check_mandatory:
	if [ "$(LIB)" ]; then \
		echo "$(YELLOW)$(LIB) $(GREEN)was created correctly!"; \
	else \
		echo "$(RED)Something went wrong in creating $(YELLOW)$(LIB)!"; \
	fi 

clean: check_clean wait
	$(MAKE) -C $(DIR) clean
	clear

check_clean:
	if ls $(DIR)/*.o > /dev/null 2>&1;  then \
		echo "$(GREEN)Everything was cleaned correctly!"; \
	else \
		echo "$(RED)Something went wrong in clean!"; \
	fi 

fclean: check_fclean wait
	$(MAKE) -C $(DIR) fclean
	$(RMDIR) $(LIB_DIR)
	clear

check_fclean: 
	if ls $(LIB_DIR)/$(LIB) > /dev/null 2>&1;  then \
		echo "$(YELLOW)$(LIB) $(GREEN)and $(BLUE)$(LIB_DIR) $(GREEN)were removed correctly!"; \
	else \
		echo "$(RED)Something went wrong in fclean!"; \
	fi 

re: fclean all
	$(MAKE) -C $(DIR) re
	clear

norm:
	norminette *

wait:
	sleep 1

.PHONY: all clean fclean re norm
.SILENT:
