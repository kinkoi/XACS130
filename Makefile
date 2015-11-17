SOURCE_DIR=./src
CC=gcc
BUILD_DIR=./build
BIN_DIR=./bin
CFLAGS=-I${SOURCE_DIR}

_DEPS = util.h
DEPS = $(patsubst %,$(SOURCE_DIR)/%, $(_DEPS))

_OBJ = util.o onetimepad.o
OBJ = $(patsubst %,$(BUILD_DIR)/%, $(_OBJ))

$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

onetimepad: $(BUILD_DIR)/util.o $(BUILD_DIR)/onetimepad.o
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/*.o
