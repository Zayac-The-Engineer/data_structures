##
# Data structure thingy
#
# @file
# @version 0.1
CC          := gcc
MKDIR		:= mkdir
RMDIR		:= rm -r
BIN         := ./bin
OBJ         := ./obj
INCLUDE     := ./include
SRC	        := ./src
SRCS        := $(wildcard $(SRC)/*.c)
OBJS        := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
TARGET      := $(BIN)/prog
CFLAGS      := -I$(INCLUDE)
LDLIBS      := -lm
DEBUGFLAGS  := -ggdb -O0

.PHONY: clean all run debug

debug: CFLAGS = $(CFLAGS) $(DEBUGFLAGS)
debug: all

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$<

$(BIN) $(OBJ):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(BIN)
# end
