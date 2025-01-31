NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
MY_SOURCES = ft_printf.c \
			ft_printf_decimal.c \
			ft_printf_hex.c \
			ft_printf_ptr.c \
			ft_printf_str.c \
			ft_printf_unsigned.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar crs $(NAME) $(MY_OBJECTS)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
