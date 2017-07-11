##
## Makefile for rt in /home/boutte_p/rendu/infographie/gfx_raytracer1
## 
## Made by bouttereux philippe
## Login   <boutte_p@epitech.net>
## 
## Started on  Fri Feb 19 13:13:55 2016 bouttereux philippe
## Last update Sun May 22 21:40:21 2016 Desriac
##

CC		=	clang

NAME		=	raytracer2

MY		=	src/my/

SETD		=	src/set_data/

PTHREAD		=	src/pthread/

SCREEN		=	src/screen/

INTER		=	src/inter/

MOVE		=	src/move/

EFFECT		=	src/effects/

LDFLAGS		=	-L/home/${USER}/.froot/lib/ -llapin 	\
			-L/usr/local/lib 			\
			-lsfml-audio 				\
			-lsfml-graphics 			\
			-lsfml-window 				\
			-lsfml-system 				\
			-lstdc++ -ldl 				\
			-lpthread				\
			-lm					\

SRC		=	src/main.c        	\
			$(MY)my_getnbr.c	\
			$(MY)my_str.c		\
			$(MY)my_error.c		\
			$(MY)pixel.c		\
			$(MY)my_puts.c		\
			$(SETD)set_data.c	\
			$(SETD)set_obj.c	\
			$(SETD)set_obj2.c	\
			$(SETD)get_scop.c	\
			$(PTHREAD)rt.c		\
			$(PTHREAD)fct_thread.c	\
			$(SCREEN)screen.c	\
			$(INTER)hit_obj.c	\
			$(INTER)hit_light.c	\
			$(INTER)inter.c		\
			$(INTER)plan_inter.c	\
			$(INTER)inter_sq.c	\
			$(INTER)math.c		\
			$(INTER)fill.c		\
			$(INTER)fill_plan.c	\
			$(INTER)ligth_fill.c	\
			$(INTER)ligth_fillp.c	\
			$(MOVE)move.c		\
			$(EFFECT)effects.c	\
			$(EFFECT)guitar.c	\


CFLAGS		+=	-W -Wall -Wextra -Werror			\
			-I/home/${USER}/.froot/include -I./include/

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CAT		=	cat

ECHO		=	/bin/echo -e

all:		flag $(NAME)

flag:
		@$(ECHO) "\n\033[0;31mFLAGS : \033[00m" $(CFLAGS) "\n"

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		@$(ECHO) "\n\033[1;34m >> \033[0;32mCompiled \033[1;34m<<\033[00m\n"

clean:
		@$(RM) $(OBJ)
		@$(ECHO) "\033[0;32mClean OBJ Files\033[00m"

fclean:		clean
		@$(ECHO) "\033[0;32mClean Binary\033[00m"

re:		fclean all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		$(ECHO) "\033[0;32m ◉  »\033[1;34m" $< "\033[00m" || \
		$(ECHO) "\033[0;31m ⊗  »\033[1;34m" $< "\033[00m"

.PHONY:		all clean fclean re

philippe:	$(CAT) ./lol
