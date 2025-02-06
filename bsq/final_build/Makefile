# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Executable name
NAME = bsq

# List of source files
SRC = main.c \
	find_largest_square.c \
	largest_square_helper.c \
	write_error.c \
	map_is_valid.c \
	make_arr.c \
	find_marks.c \
	process_stdin.c

# List of object files (corresponding to the source files)
OBJ = $(SRC:.c=.o)

# Default rule to build the program
all: $(NAME)

# Link the object files into the final executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJ)

# Remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets (these are not actual files)
.PHONY: all clean fclean re
