CC		= gcc
CFLAGS	= -Wall -Werror -Wall
LFLAGS	= -L./libft/ -lft
MAKELIB	= make -C libft/
RM		= rm -f
NAME	= pipex
HEAD	= pipex.h
OBJ		= \
main.o pipex.o children.o utils.o

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

%.o:		%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKELIB) fclean
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re