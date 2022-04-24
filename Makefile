CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
SRC_DIR = ./src/
OBJ_DIR = ./obj/
BIN_DIR = ./bin/
TEST_DIR = ./test/
LIB_DIR = ./src/lib/

CC = gcc
TARGET = chessviz
TEST_TARGET = chessviz_test

TEST = $(wildcard $(TEST_DIR)*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST))
POST_TEST = $(patsubst ./%.c, $(OBJ_DIR)%.o, $(TEST))

SRC = $(wildcard $(SRC_DIR)*/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
POST_OBJ = $(patsubst ./%.c, $(OBJ_DIR)%.o, $(SRC))

LIB = $(wildcard $(LIB_DIR)*.c)
LIB_OBJ = $(patsubst %.c, %.o, $(LIB))
POST_LIB = $(patsubst ./%.c, $(OBJ_DIR)%.o, $(LIB))

all : $(BIN_DIR)$(TARGET)

$(BIN_DIR)$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(POST_OBJ) -o $(BIN_DIR)$(TARGET)

.PHONY: test
test : $(TEST_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(SRC_DIR) $(POST_LIB) $(POST_TEST) -o $(BIN_DIR)$(TEST_TARGET)
	
%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(SRC_DIR) -c $< -o $(OBJ_DIR)$@

-include %.d

clean : 
	rm $(POST_OBJ) $(BIN_DIR)$(TARGET) $(OBJ_DIR)*/*/*.d $(POST_TEST) $(PREF_OBJ)*/*.d
