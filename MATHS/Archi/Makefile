##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## epitech > epita
##
NAME	= > 102architect

all: $(NAME)

$(NAME):
			cp architect.py 102architect
			chmod +x 102architect

clean:

fclean:
	rm -rf 102architect

re:			fclean all

run_all_tests:
		pytest tests/tests.py -v --color=yes

.PHONY:		all clean fclean re run_tests
