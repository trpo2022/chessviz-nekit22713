CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

BIN_DIR = ./bin/
OBJ_DIR = ./obj/
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_FILE = $(patsubst ./%.c, $(OBJ_DIR)%.o, $(SRC))
CC = gcc
NAME = chessviz

$(BIN_DIR)$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ_FILE) -o $(BIN_DIR)$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(SRC_BIN) -c $< -o $(OBJ_DIR)$@

-include %.d

.PHONY: clean
clean : 
	rm $(OBJ_FILE) $(BIN_DIR)$(NAME) $(OBJ_DIR)*/*/*.d
