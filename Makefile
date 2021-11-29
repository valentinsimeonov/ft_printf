NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = ft_printf.c functions_d_i_c_s.c functions_hexa.c \
functions_p_u_percent.c libfthelp.c

OBJ := $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all