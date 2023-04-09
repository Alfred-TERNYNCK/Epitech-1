##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## epitech > epita
##

NAME	= 108trigo

all: $(NAME)

$(NAME):
			touch $(NAME)
			echo "#!/usr/bin/python3" > $(NAME)
			cat main.py >> $(NAME)
			chmod +x $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
