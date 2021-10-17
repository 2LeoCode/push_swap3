SHELL=bash
OS=$(shell uname)

NAME=checker push_swap

.SUFFIXES=.c .o .h

INCD=inc
SRCD=src
LIBD=lib
OBJD=.obj

SUBD=$(addprefix common/, get_next_line queue stack utils stack_instructions get_stacks exception) checker push_swap push_swap push_swap_bonus

COMMON_SRC=$(wildcard $(SRCD)/common/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))
CHECKER_SRC=$(wildcard $(SRCD)/checker/*$(word 1, $(.SUFFIXES)))
CHECKER_OBJ=$(CHECKER_SRC:$(SRCD)/%$(word 1, $(.SUFFIXES)=$(OBJD)/%$(word 2, $(.SUFFIXES)))
RESOLVER_SRC=$(wildcard $(SRCD)/push_swap/*$(word 1, $(.SUFFIXES)))
RESOLVER_OBJ=$(COMMON_SRC:$(SRCD)/%$(word 1, $(.SUFFIXES)=$(OBJD)/%$(word 2, $(.SUFFIXES)))
RESOLVER_BONUS_SRC=$(wildcard $(SRCD)/push_swap_bonus/*$(word 1, $(.SUFFIXES)))
RESOLVER_BONUS_OBJ=$(COMMON_SRC:$(SRCD)/%$(word 1, $(.SUFFIXES))=$(OBJD)/%$(word 2, $(.SUFFIXES)))

INC=$(wildcard $(INCDIR)/*$(word 3, $(.SUFFIXES)))
SRC=$(COMMON_SRC) $(CHECKER_SRC) $(RESOLVER_SRC)
OBJ=$(COMMON_OBJ) $(CHECKER_OBJ) $(RESOLVER_OBJ)

CC=clang
CFLAGS=-Wall -Werror -Wextra -I $(INCD) #-fsanitize=address
MFLAGS=--no-print-directory

export SHELL
export OS
export .SUFFIXES
export CC
export MFLAGS

all: $(NAME)

fall: $(addprefix f, $(NAME))

$(OBJD)/common/%$(word 2, $(.SUFFIXES)): $(SRCD)/common/%$(word 1, $(.SUFFIXES)) $(INC) $(wildcard $(INCD)/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

push_swap: $(OBJD) $(COMMON_OBJ)
	$(MAKE) $(MFLAGS) -C $(SRCD)/$@
	cp $(SRCD)/$@/$@ .

fpush_swap: $(OBJD) $(COMMON_OBJ)
	$(MAKE) $(MFLAGS) -C $(SRCD)/push_swap
	cp $(SRCD)/push_swap/push_swap .

checker: $(OBJD) $(COMMON_OBJ)
	$(MAKE) $(MFLAGS) -C $(SRCD)/checker
	cp $(SRCD)/checker/checker .

fchecker: $(OBJD) $(COMMON_OBJ)
	$(MAKE) $(MFLAGS) -C $(SRCD)/checker
	cp $(SRCD)/checker/checker .

bonus: $(OBJD) $(COMMON_OBJ)
	$(MAKE) $(MFLAGS) -C $(SRCD)/push_swap_bonus
	cp $(SRCD)/push_swap_bonus/push_swap .

clean_common:
	rm -f $(COMMON_OBJ)

clean: clean_common
	$(foreach dir, $(NAME) push_swap_bonus, $(MAKE) fclean $(MFLAGS) -C $(SRCD)/$(dir);)

fclean: clean_common
	rm -f $(NAME)
	$(foreach dir, $(NAME) push_swap_bonus, $(MAKE) fclean $(MFLAGS) -C $(SRCD)/$(dir);)

re: fclean all

$(OBJD):
	mkdir -p $(addprefix $@/, $(SUBD))

test: all
	cp checker test
	cp push_swap test

.PHONY: all fall fchecker fpush_swap clean fclean re bonus test
