NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_put_stuff.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I ./
RM = rm -f
DEPS = $(SRCS:.c=.d)
%.o: %.c
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
-include $(DEPS)
clean:
	$(RM) $(OBJS) $(DEPS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re