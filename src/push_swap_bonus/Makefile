SHELL=bash
OS=$(shell uname)

NAME=push_swap
.SUFFIXES=.c .o .h

SRCD=.
OBJD=../../.obj/push_swap_bonus
INCD=../../inc ../../lib/minilibx-linux
LIBD=../../lib

COMMON_SRCD=../common
COMMON_OBJD=../../.obj/common
COMMON_SRC=$(wildcard $(COMMON_SRCD)/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(COMMON_SRCD)/%$(word 1, $(.SUFFIXES)), $(COMMON_OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))

SRC=$(COMMON_SRC) $(wildcard $(SRCD)/*.c)
OBJ=$(COMMON_OBJ) $(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(wildcard $(SRCD)/*.c))
LIB=minilibx-linux
LIBNAME=minilibx-Linux.a

CC=clang
INCFLAGS=$(addprefix -I, $(INCD))
CFLAGS=-Wall -Werror -Wextra $(INCFLAGS) -O3 #-fsanitize=address
LCFLAGS=-L $(LIBD) -lXext -lX11 -lm -lz -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	$(foreach dir, $(LIB), $(MAKE) -C $(LIBD)/$(dir))
	cp $(LIBD)/*/*.a $(LIBD)
	$(CC) $(INCFLAGS) $^ -o $@ $(LCFLAGS)

$(OBJD)/%$(word 2, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) $(wildcard $(INCD)/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(foreach dir, $(LIB), $(MAKE) clean -C $(LIBD)/$(dir))
	@rm -f $(LIBD)/*.a $(OBJ)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

init:
	mkdir $(OBJD) $(COMMON_OBJD)

.PHONY: all clean fclean re init
