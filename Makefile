CC		=	gcc

NAME		=	forza

SRC		=	main.c					\
			include/libmy.c			\
			include/menu.c 			\
			include/tableau.c 		\
			include/mouvement.c 	\
			include/mouvement2.c 	\

CFLAGS		=	-W -Werror -Wextra -Wall

RM		=	rm -f

all:
		$(CC) $(CFLAGS) $(SRC) -L. $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(NAME) ./*~

fclean: 	clean
		$(RM) $(NAME) a.out

re:		fclean all

.PHONY:		all clean fclean re