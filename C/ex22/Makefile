CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

SRC_DIR=./src
OBJ_DIR=./objs
BUILD_DIR=./build
TESTS_DIR=./tests

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(SOURCES:%.c=%.o)

TEST_SRC=$(wildcard $(TESTS_DIR)/*_tests.c)
TESTS=$(patsubst %.c,%.exe,$(TEST_SRC))

TARGET=$(BUILD_DIR)/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
#all: $(TARGET) $(SO_TARGET) tests


all: target tests

target: build $(TARGET) $(SO_TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(OBJECTS)	
	$(CC) -shared -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(TESTS_DIR)/%.exe: $(TESTS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)


build:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(TESTS_DIR)

# The Unit Tests
.PHONY: tests

tests: $(TESTS)
	sh ./tests/runtests.sh


# The Cleaner
clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR) || true
	rm $(OBJECTS) || true
	rm $(TESTS) || true
