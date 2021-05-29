SRCS		= get_next_line.c\
			  get_next_line_utils.c\
			  main.c\

OBJS		= $(SRCS:.c=.o)

NAME		= get_next_line

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -Iincludes -D BUFFER_SIZE=42

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
					@$(CC) $(CFLAGS) $^
					@echo "gnl compiled"

clean:
					@$(RM) $(OBJS)
					@echo ".o deleted"

fclean:		clean
					@$(RM) $(NAME)
					@echo "exec deleted"

re:			fclean all

.PHONY:		all clean fclean re
