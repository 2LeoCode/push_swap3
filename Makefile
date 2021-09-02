SHELL=bash
OS=$(shell uname)

NAME=checker resolver
.SUFFIXES=.c .o .h

INCD=inc
SRCD=src
LIBD=lib
OBJD=.obj
SUBD=$(addprefix common/, get_next_line queue stack) $(addprefix checker/, )\
$(addprefix resolver/, )

INC=$(wildcard $(INCDIR)/*$(word 3, $(.SUFFIXES)))
SRC=$(foreach exec, $(NAME), $(wildcard $(SRCD)/$(exec)/*$(word 1, $(.SUFFIXES))))\
	$(foreach dir, $(SUBD),\
	$(wildcard $(SRCD)/$(dir)/*$(word 1, $(.SUFFIXES)))\
	$(wildcard $(SRCD)/$(dir)/*/*$(word 1, $(.SUFFIXES))))
OBJ=$(SRC:$(SRCD)/%$(word 1, $(.SUFFIXES))=$(OBJD)/%$(word 2, $(.SUFFIXES)))

CC=gcc
CFLAGS=-Wall -Werror -Wextra -I $(INCD) #-fsanitize=address

all: $(OBJ) $(NAME)

$(OBJD)/%$(word 2, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES))
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): %: $(subst $(word 1, $(.SUFFIXES)), $(word 2, $(.SUFFIXES)),\
$(subst $(SRCD)/, $(OBJD)/, $(wildcard $(SRCD)/%/*$(word 1, $(.SUFFIXES)))\
$(wildcard $(SRCD)/%/*/*$(word 1, $(.SUFFIXES)))))
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

init:
	mkdir -p $(addprefix $(OBJD)/, $(SUBD))

debug:
	@echo 'Subdirectories: $(SUBD)'
	@echo 'Sources: $(SRC)'
	@echo 'Objects: $(OBJ)'
