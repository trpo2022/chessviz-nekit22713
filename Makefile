CFLAGS = -Wall -Wextra -Werror
CPdPFLAGS = -MMD
PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_BIN = ./bin/
PREF_TEST = ./test/
PREF_LIB = ./src/lib/

CC = gcc
TARGET = chessviz
TEST_TARGET = chessviz_test

TEST = $(wildcard $(PREF_TEST)*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST))
POST_TEST = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(TEST))
SRC = $(wildcard $(PREF_SRC)*/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
POST_OBJ = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(SRC))
STATIC = ./obj/src/lib/static.a
LIB = $(wildcard $(PREF_LIB)*.c)
LIB_OBJ = $(patsubst %.c, %.o, $(LIB))
POST_LIB = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(LIB))

.PHONY: all
all : $(PREF_BIN)$(TARGET)

$(PREF_BIN)$(TARGET) : ./src/main/chessviz.o $(STATIC)
	$(CC) $(CFLAGS) ./obj/src/main/chessviz.o $(STATIC) -o $(PREF_BIN)$(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(PREF_SRC) -c $< -o $(PREF_OBJ)$@

-include %.d

$(STATIC) : $(LIB_OBJ)
	ar rcs $@ $(POST_LIB)

.PHONY: test
test : $(TEST_OBJ) $(STATIC)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(PREF_SRC) $(POST_TEST) $(STATIC) -o $(PREF_BIN)$(TEST_TARGET)

.PHONY: clean
clean :
	rm $(POST_OBJ) $(PREF_BIN)$(TARGET) $(PREF_OBJ)*/*/*.d $(POST_TEST) $(PREF_OBJ)*/*.d $(PREF_OBJ)*/*/*.a $(PREF_BIN)$(TEST_TARGET)
