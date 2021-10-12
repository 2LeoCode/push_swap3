SHELL=bash
OS=$(shell uname)

NAME=checker
.SUFFIXES=.c .o .h

SRCD=.
OBJD=../../.obj/checker
INCD=../../inc

COMMON_SRCD=../common
COMMON_OBJD=../../.obj/common
COMMON_SRC=$(wildcard $(COMMON_SRCD)/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(COMMON_SRCD)/%$(word 1, $(.SUFFIXES)), $(COMMON_OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))

SRC=$(COMMON_SRC) $(wildcard $(SRCD)/*.c)
OBJ=$(COMMON_OBJ) $(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(wildcard $(SRCD)/*.c))

CC=clang
CFLAGS=-Wall -Werror -Wextra -I $(INCD) #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJD)/%$(word 2, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) $(wildcard $(INCD)/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

init:
	mkdir $(OBJD) $(COMMON_OBJD)

.PHONY: all clean fclean re init
