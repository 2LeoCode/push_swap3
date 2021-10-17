NAME=push_swap

SRCD=.
OBJD=../../.obj/push_swap
INCD=../../inc

COMMON_SRCD=../common
COMMON_OBJD=../../.obj/common
COMMON_SRC=$(wildcard $(COMMON_SRCD)/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(COMMON_SRCD)/%$(word 1, $(.SUFFIXES)), $(COMMON_OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))

SRC=$(wildcard $(SRCD)/*.c)
OBJ=$(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(SRC))

INCFLAGS=$(addprefix -I, $(INCD))
CFLAGS=-Wall -Werror -Wextra #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(COMMON_OBJ) -o $@

$(OBJD)/%$(word 2, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES))
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

init:
	mkdir $(OBJD)

.PHONY: all clean fclean re init
