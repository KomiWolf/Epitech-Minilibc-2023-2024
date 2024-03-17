##
## EPITECH PROJECT, 2024
## MiniLibC
## File description:
## Makefile
##

SRC	=	./src/my_strlen.asm \
		./src/my_strchr.asm \
		./src/my_strrchr.asm \
		./src/my_strcmp.asm \
		./src/my_strncmp.asm \
		./src/my_strcspn.asm \
		./src/my_strpbrk.asm \
		./src/my_strstr.asm \
		./src/my_strcasecmp.asm \
		./src/my_memset.asm \
		./src/my_memcpy.asm \
		./src/my_memmove.asm \
		./src/bonus_ffs.asm \

OBJ	=	$(SRC:.asm=.o)

CC	=	gcc

RM	=	rm -f

NASM	=	nasm

NASMFLAGS	=	-f elf64

LD	=	ld

LDFLAGS	=	-shared

NAME	=	libasm.so

TESTSRC	=	./tests/test_my_strlen.c \
			./tests/test_my_strchr.c \
			./tests/test_my_strrchr.c \
			./tests/test_my_strcmp.c \
			./tests/test_my_strncmp.c \
			./tests/test_my_strcspn.c \
			./tests/test_my_strpbrk.c \
			./tests/test_my_strstr.c \
			./tests/test_my_strcasecmp.c \
			./tests/test_my_memset.c \
			./tests/test_my_memcpy.c \
			./tests/test_my_memmove.c \
			./tests/test_bonus_ffs.c \

TESTNAME	=	unit_tests

CPPFLAGS	=	-iquote ./include

TESTFLAGS	=	--coverage -lcriterion

%.o:	%.asm
		$(NASM) $(NASMFLAGS) $< -o $@

all:	$(OBJ)
		$(LD) $(LDFLAGS) $(OBJ) -o $(NAME)

tests_run:	all
			$(CC) $(TESTSRC) -o $(TESTNAME) $(TESTFLAGS) $(CPPFLAGS)
			./$(TESTNAME)

coverage:
			gcovr --exclude /tests
			gcovr --exclude /tests --branches

clean:
		$(RM) $(OBJ)
		$(RM) *.gcda
		$(RM) *.gcno


fclean: clean
		$(RM) $(NAME)
		$(RM) $(TESTNAME)

re:	fclean all

.PHONY:	all tests_run coverage clean fclean re
