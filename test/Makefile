##
# tests
#
# @file
# @version 0.1

CC			:= gcc
MKDIR		:= mkdir
RMDIR		:= rm -rf

SRC			:= .
OBJ			:= ../obj/test
LIB			:= ../lib
BIN			:= ../bin/test
INCLUDE		:= ../include
RUNSUFFIX	:= _run

SRCS		:= $(wildcard $(SRC)/*.c)
OBJS		:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
LIBS		:= $(wildcard $(LIB)/*.a)
TARGETS		:= $(patsubst $(SRC)/%.c, $(BIN)/%, $(SRCS))
RUNTARGETS	:= $(addsuffix $(RUNSUFFIX), $(TARGETS))

CFLAGS		:= -I$(INCLUDE)
DEBUGFLAGS	:= -ggdb -O0


.PHONY: all clean debug run $(RUNTARGETS)

all: $(TARGETS)

debug: CFLAGS := $(CFLAGS) $(DEBUGFLAGS)
debug: all

run: all $(RUNTARGETS)

$(RUNTARGETS):%$(RUNSUFFIX):%
	./$<

$(BIN)/%: $(OBJ)/%.o $(LIBS) | $(BIN)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(BIN)

# end
