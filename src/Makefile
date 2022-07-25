##
# data_stuctures lib
#
# @file
# @version 0.1

CC			:= gcc
MKDIR		:= mkdir
RMDIR		:= rm -rf

SRC			:= .
OBJ			:= ../obj/datastructures
LIB			:= ../lib
INCLUDE		:= ../include

SRCS		:= $(wildcard $(SRC)/*.c)
OBJS		:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TARGET		:= $(LIB)/datastructures.a

CFLAGS		:= -I$(INCLUDE)
DEBUGFLAGS	:= -ggdb -O0

.PHONY: all clean debug

all: $(TARGET)

debug: CFLAGS := $(CFLAGS) $(DEBUGFLAGS)
debug: all

$(TARGET): $(OBJS) | $(LIB)
	ar rcs $@ $^

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) $(LIB):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(LIB)

# end
