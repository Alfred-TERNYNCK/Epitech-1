##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

NAME	= push_swap

CC		= gcc

RM		= rm -f

SRC		= src/main.c \
		src/calc.c \
		src/calc_list.c \
		src/check_sort.c \
		src/display_result.c \
		src/swap_pa.c \
		src/swap_pb.c \
		src/swap_ra.c \
		src/swap_rb.c \
		src/swap_sa.c \
		src/swap_sb.c \

OBJ		= $(SRC:.c=.o)

LIBFLAG	= -L lib/my/ -lmy

CFLAGS = -I include/

all: $(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG) $(CFLAGS)


clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C lib/my clean
	$(RM) *.gcno *.gcda

fclean:		clean
	rm -rf $(NAME)
	$(MAKE) fclean -C lib/my fclean

re:			fclean all

test_run : $(MAKE) -C ../tests

.phony:	all clean fclean re
