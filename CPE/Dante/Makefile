##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

SRC_GENERATOR= generator/src/main.c\
							generator/src/generator.c\
							generator/src/get_info.c\
							generator/src/place_maze.c\
							generator/src/random.c\
							generator/src/utils.c

SRC_SOLVER= solver/src/main.c\
							solver/src/solver.c\
							solver/src/utils.c \
							solver/src/node_function.c \
							solver/src/check_maze.c

OBJS_GENERATOR= $(SRC_GENERATOR:.c=.o)

OBJS_SOLVER= $(SRC_SOLVER:.c=.o)

N_GENERATOR= generator/generator

N_SOLVER= solver/solver

CC = gcc

CFLAGS = -I include/ -Wall -Wextra -Werror

RM= rm -f

all:	$(N_GENERATOR) $(N_SOLVER)

$(N_GENERATOR):	$(OBJS_GENERATOR)
			$(CC) -o $(N_GENERATOR) $(OBJS_GENERATOR)

$(N_SOLVER):	$(OBJS_SOLVER)
			$(CC) -o $(N_SOLVER) $(OBJS_SOLVER)

clean:
			$(RM) $(OBJS_GENERATOR)
			$(RM) $(OBJS_SOLVER)

fclean:
			make clean
			$(RM) $(N_GENERATOR)
			$(RM) $(N_SOLVER)

re: 		fclean all

.PHONY: all clean fclean re
