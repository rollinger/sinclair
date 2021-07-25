# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 19:38:12 by prolling          #+#    #+#              #
#    Updated: 2021/07/24 19:50:31 by prolling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

buff = buff/*.c buff/*.h
#math = math/*.c math/*.h
#stats = stats/*.c stats/*.c
header = sinclair.h

SOURCES	=	$(header) $(buff) $(math) $(stats)

NAME = libsinclair.a
DNAME = libsinclair.so
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIB = ar rc

ifdef WITH_DEBUG
	DEBUG = -g
else
	DEBUG =
endif

$(NAME): clean
	gcc -c $(DEBUG) $(FLAGS) $(SOURCES)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	mv $(NAME) ../bin/
	rm -f *.o *.gch

$(DNAME): clean
	gcc -shared $(DEBUG) $(SOURCES) -o $(DNAME)
	mv $(DNAME) ../bin/
	rm -f *.o *.gch

all: $(NAME)

lib:
	$(NAME)

dynlib:
	$(DNAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
