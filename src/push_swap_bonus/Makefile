NAME=push_swap

SRCD=.
OBJD=../../.obj/push_swap_bonus
INCD=../../inc ../../lib/minilibx-linux
LIBD=../../lib

COMMON_SRCD=../common
COMMON_OBJD=../../.obj/common
COMMON_SRC=$(wildcard $(COMMON_SRCD)/*/*$(word 1, $(.SUFFIXES)))
COMMON_OBJ=$(patsubst $(COMMON_SRCD)/%$(word 1, $(.SUFFIXES)), $(COMMON_OBJD)/%$(word 2, $(.SUFFIXES)), $(COMMON_SRC))
SRC=$(wildcard $(SRCD)/*.c)
OBJ=$(patsubst $(SRCD)/%$(word 1, $(.SUFFIXES)), $(OBJD)/%$(word 2, $(.SUFFIXES)), $(SRC))

LIB=minilibx-linux
LIBNAME=minilibx-Linux.a

INCFLAGS=$(addprefix -I, $(INCD))
CFLAGS=-Wall -Werror -Wextra -O3 #-fsanitize=address
LCFLAGS=-L $(LIBD) -lXext -lX11 -lm -lz -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	$(foreach dir, $(LIB), $(MAKE) $(MFLAGS) -C $(LIBD)/$(dir))
	cp $(LIBD)/*/*.a $(LIBD)
	$(CC) $(CFLAGS) -O3 $^ $(COMMON_OBJ) -o $@ $(LCFLAGS)

$(OBJD)/%$(word 2, $(.SUFFIXES)): $(SRCD)/%$(word 1, $(.SUFFIXES)) $(wildcard $(INCD)/*.h)
	$(CC) $(CFLAGS) $(INCFLAGS) -O3 -c $< -o $@

clean:
	$(foreach dir, $(LIB), $(MAKE) clean -s -C $(LIBD)/$(dir))
	rm -f $(LIBD)/*.a $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
