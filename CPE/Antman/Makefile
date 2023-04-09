##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

SRC_GIATMAN= giantman/src/main.c\

SRC_ANTMAN= antman/src/main.c\

OBJS_ANTMAN= $(SRC_ANTMAN:.c=.o)

OBJS_GIATMAN= $(SRC_GIATMAN:.c=.o)

N_ANTMAN= antman/antman

N_GIATMAN= giantman/giantman

CC = gcc

LIBFLAGS = -L lib/my/ -lmy -lm

CFLAGS = -I include/

RM= rm -f

all:	$(N_ANTMAN) $(N_GIATMAN)

$(N_ANTMAN):	$(OBJS_ANTMAN)
			make -C lib/my/
			$(CC) -o $(N_ANTMAN) $(OBJS_ANTMAN) $(LIBFLAGS)

$(N_GIATMAN):	$(OBJS_GIATMAN)
			make -C lib/my/
			$(CC) -o $(N_GIATMAN) $(OBJS_GIATMAN) $(LIBFLAGS)

clean:
			make clean -C lib/my/
			$(RM) $(OBJS_ANTMAN)
			$(RM) $(OBJS_GIATMAN)

fclean:
			make clean
			make fclean -C lib/my/
			$(RM) $(N_ANTMAN)
			$(RM) $(N_GIATMAN)

re: 		fclean all

.PHONY: all clean fclean re
