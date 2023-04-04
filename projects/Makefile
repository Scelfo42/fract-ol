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

GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

all: $(NAME)

$(NAME): dir check_mandatory
	$(MAKE) -C $(DIR)
	mv -u $(DIR)/$(LIB) $(LIB_DIR)
	clear

dir:
	if [ -d "$(DIR)" ]; then \
		echo "$(GREEN)PERFECT! $(BLUE)$(DIR) $(GREEN)exists!$(NC)"; \
	else \
		echo "$(RED)ERROR! $(DIR) doesn't exist$(NC)"; \
	fi
	mkdir -p $(LIB_DIR)

check_mandatory:
	if [ "$(LIB)" ]; then \
		echo "$(YELLOW)$(LIB) $(GREEN)was created correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in creating $(YELLOW)$(LIB)!$(NC)"; \
	fi 

clean: check_clean wait
	$(MAKE) -C $(DIR) clean
	clear

check_clean:
	if ls $(DIR)/*.o > /dev/null 2>&1;  then \
		echo "$(GREEN)Everything was cleaned correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in clean!$(NC)"; \
	fi 

fclean: check_fclean wait
	$(MAKE) -C $(DIR) fclean
	$(RMDIR) $(LIB_DIR)
	clear

check_fclean: 
	if ls $(LIB_DIR)/$(LIB) > /dev/null 2>&1;  then \
		echo "$(YELLOW)$(LIB) $(GREEN)and $(BLUE)$(LIB_DIR) $(GREEN)were removed correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in fclean!$(NC)"; \
	fi 

re: fclean all
	$(MAKE) -C $(DIR) re
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
	norminette *

wait:
	sleep 1

.PHONY: all clean fclean re norm push
.SILENT:
