##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compiler
##

SRCS= my_putchar.c \
		  my_isneg.c \
		  my_put_nbr.c \
		  my_put_nbr_base.c \
		  my_swap.c \
		  my_putstr.c \
		  my_strlen.c \
		  my_getnbr.c \
		  my_sort_int_array.c \
		  my_compute_power_rec.c \
		  my_compute_square_root.c \
		  my_is_prime.c \
		  my_find_prime_sup.c \
		  my_strcpy.c \
		  my_strncpy.c \
		  my_revstr.c \
		  my_strstr.c \
		  my_strcmp.c \
		  my_strncmp.c \
		  my_strupcase.c \
		  my_strlowcase.c \
		  my_strcapitalize.c \
		  my_str_isalpha.c \
		  my_str_isnum.c \
		  my_str_islower.c \
		  my_str_isupper.c \
		  my_str_isprintable.c \
		  my_showstr.c \
		  my_showstr.c \
		  my_showmem.c \
		  my_strcat.c \
		  my_strncat.c \
		  my_char_isalpha.c \
		  get_params_float_flag.c \
		  my_putstr_plus.c \
		  my_char_isprintable.c \
		  power_of_10.c \
		  convert_float_to_int.c \
		  my_put_nbr_base_hex.c \
		  my_str_to_word_array.c \
		  my_is_a_number.c \

OBJS= $(SRCS:.c=.o)

NAME= libmy.a

RM= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			cp libmy.a ../libmy.a
			make clean

clean:		clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) ../libmy.a

re: 		fclean all
