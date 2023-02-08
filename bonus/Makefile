NAME = libftprintf.a
BONUS = .bonus
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_put_stuff.c
SRCSBONUS = ft_printf_bonus.c ft_put_nums_bonus.c ft_put_text_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
INCLUDE = -I ./
RM = rm -f
DEPS = $(SRCS:.c=.d)
DEPS_BONUS = $(SRCSBONUS:.c=.d)
%.o: %.c
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
-include $(DEPS)
bonus: $(BONUS)
$(BONUS) : $(OBJSBONUS)
	ar -rcs $(NAME) $(OBJSBONUS)
	@touch $(BONUS)
-include $(DEPS_BONUS)
clean:
	$(RM) $(OBJS) $(DEPS) $(OBJSBONUS) $(DEPS_BONUS)
fclean: clean
	$(RM) $(NAME) $(BONUS)
re: fclean all
.PHONY: all clean fclean re bonus