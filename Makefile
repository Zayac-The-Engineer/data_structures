##
# data structure project thing
#
# @file
# @version 0.1

MAKE		:= make
MKDIR		:= mkdir
RMDIR		:= rm -rf

SRC			:= ./src
TEST		:= ./test
OBJ			:= ./obj
BIN			:= ./bin
LIB			:= ./lib

TARGET		:= all

.PHONY: all clean debug test libs run

all: test

debug: TARGET := debug
debug: all

run: all
	$(MAKE) -C $(TEST) $@

test: libs | $(BIN)
	$(MAKE) -C $(TEST) $(TARGET)

libs: | $(LIB) $(OBJ)
	$(MAKE) -C $(SRC) $(TARGET)

$(OBJ) $(BIN) $(LIB):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(BIN) $(LIB)

# end
