NAME = testsuite
FLAGS = -Wall -Wextra -Werror
CC = gcc
DEBUGGER = gdb
TESTTARGET = -lsinclair -L../bin

sources = test.h test.c cases.c

$(NAME): clean
	cd ../src && make
	gcc $(FLAGS) $(sources) $(TESTTARGET) -lcmocka -o $(NAME)
	mv $(NAME) ../bin/

testrun: $(NAME)
	./../bin/$(NAME)

debug: $(NAME)
	gcc $(FLAGS) -g $(sources) $(TESTTARGET) -lcmocka -o debug
	mv debug ../bin/
	$(DEBUGGER) ../bin/debug

all:  $(NAME)

clean:
	rm -f *.o *.gch

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:	all clean fclean re
