##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## epitech > epita
##

NAME	= 107transfer

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

coding-style:
	find . -iname "*.py" -not -path "./tests/*" | xargs -n1 -I {}  pylint --output-format=colorized {}; true

.PHONY:		all clean fclean re
