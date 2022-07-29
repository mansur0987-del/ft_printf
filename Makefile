FLAG = -MMD -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_printf_helper.c

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

OBJBON = $(SRCBON:.c=.o)

SRC_D =	$(SRC:.c=.d) $(SRCBON:.c=.d)

.c.o:
	gcc $(FLAG) -c $< -o ${<:.c=.o} -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(SRC_D)
	rm -f $(OBJ)

	echo "OBJ deleted"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
