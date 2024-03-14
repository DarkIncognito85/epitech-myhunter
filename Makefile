##
## EPITECH PROJECT, 2023
## Setting up
## File description:
## Makefile
##

SOURCE	=	./src/lib/put/my_put_nbr.c							\
			./src/helpers/sf.c								\
			./src/helpers/sf2.c								\
			./src/lib/put/my_putchar.c						\
			./src/lib/put/my_putstr.c						\
			./src/set/set_position_from_window.c			\
			./src/events/on_mouse_pressed.c					\
			./src/check_pull_event.c						\
			./src/lib/my_strcmp.c							\
			./src/game.c									\
			./src/set/set_position_on_middle_window.c		\
			./src/set/set_position_text.c					\
			./src/lib/my_strlen.c							\
			./src/draw.c									\
			./src/virus.c									\
			./src/free_all.c								\
			./src/gui.c										\
			./src/lib/random_nbr.c							\
			./src/lib/my_strcat.c							\
			./src/lib/my_revstr.c							\
			./src/lib/my_itoa.c								\
			./src/check_assets.c							\
			./src/lib/check_tty.c							\
			./src/play_music.c								\

OBJS	=	$(SOURCE:.c=.o)
OUT		=	my_hunter
CC		=	gcc
CFLAGS	+=	-W -Wall -Wextra -I ./include
NAME	=	libmy.a
CSFML_FLAG = -lcsfml-graphics -lcsfml-system -lcsfml-audio -I ./include;

all: $(OUT)

$(OUT): $(OBJS)
	@ $(CC) main.c $(OBJS) -o $(OUT) $(CSFML_FLAG)
	@ echo -e "\033[1;32m$(OUT) successfully created!\033[0m"

clean:
	@ $(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o *.out
	@ echo -e "\033[1;31mAll cleaned!\033[0m"

fclean: clean
	@ rm -f *.gcno
	@ rm -f *.gcda
	@ rm -f libmy.a
	@ $(RM) $(OUT)
	@ echo -e "\033[1;31m$(OUT) (executable) is removed!\033[0m"

re: fclean all

valgrind:
	@ $(CC) $(SOURCE) main.c -o $(OUT) $(CFLAGS) -g3  $(CSFML_FLAG)
	@ echo -e "\033[1;34mRunning valgrind on $(OUT)...\033[0m"
	@ valgrind ./$(OUT)

gdb:
	@ $(CC) $(SOURCE) -o $(OUT) $(LFLAGS) $(LDFLAGS) $(CFLAGS) -g3
	@ echo -e "\033[1;34mDebugging $(OUT)...\033[0m"
	@ gdb ./$(OUT)

refresh: re
	@ ./$(OUT)
	@ echo "exit\n"
	@ ./$(OUT)

tests_run:
	@ gcc -o my_tests $(SOURCE) $(SOURCE_TEST) -lcriterion --coverage $(CFLAGS)
	./my_tests

test_print: $(OBJS)
	@ $(CC) $(SOURCE) -o $(OUT) $(LFLAGS) $(LDFLAGS) $(CFLAGS)
	make clean
	@ echo -e "\033[1;34mRunning $(OUT)...\033[0m"

csfml: $(OBJS)
	@ $(CC) main.c $(OBJS) -o $(OUT)
	ar cr $(NAME) $(OBJS)
	@ echo -e "\033[1;32m$(OUT) successfully created!\033[0m"

mango:
	make fclean
	mango
