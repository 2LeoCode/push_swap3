SHELL=bash
OS=$(shell uname)

NAME=checker resolver
.SUFFIXES=.c .o .h

INCD=inc
SRCD=src
LIBD=lib
OBJD=.obj

SUBD=$(addprefix common/, get_next_line queue stack utils stack_instructions get_stacks exception) checker resolver

COMMON_SRC=$(wildcard $(SRCD)/common/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))
CHECKER_SRC=$(wildcard $(SRCD)/checker/*$(word 1, $(.SUFFIXES)))
CHECKER_OBJ=$(CHECKER_SRC:$(SRCD)/%$(word 1, $(.SUFFIXES)=$(OBJD)/%$(word 2, $(.SUFFIXES)))
RESOLVER_SRC=$(wildcard $(SRCD)/resolver/*$(word 1, $(.SUFFIXES)))
RESOLVER_OBJ=$(COMMON_SRC:$(SRCD)/%$(word 1, $(.SUFFIXES)=$(OBJD)/%$(word 2, $(.SUFFIXES)))

INC=$(wildcard $(INCDIR)/*$(word 3, $(.SUFFIXES)))
SRC=$(COMMON_SRC) $(CHECKER_SRC) $(RESOLVER_SRC)
OBJ=$(COMMON_OBJ) $(CHECKER_OBJ) $(RESOLVER_OBJ)

CC=clang
CFLAGS=-Wall -Werror -Wextra -I $(INCD) #-fsanitize=address

all: $(NAME)

$(OBJD)/common/%$(word 2, $(.SUFFIXES)): $(SRCD)/common/%$(word 1, $(.SUFFIXES)) $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

resolver: $(COMMON_OBJ)
	$(MAKE) -C $(SRCD)/resolver
	cp $(SRCD)/resolver/resolver .

checker: $(COMMON_OBJ)
	$(MAKE) -C $(SRCD)/checker
	cp $(SRCD)/checker/checker .

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(foreach dir, $(NAME), ls; $(MAKE) fclean -C $(SRCD)/$(dir);)

re: fclean all

init:
	mkdir -p $(addprefix $(OBJD)/, $(SUBD))

debug:
	@echo 'Subdirectories: $(SUBD)'
	@echo 'Sources: $(SRC)'
	@echo 'Objects: $(OBJ)'

.PHONY: all clean fclean init debug
