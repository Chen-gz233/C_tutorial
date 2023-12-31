#CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LDLIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local)


#通过执行wildcard搜索在src/中所有*.c文件来动态创建SOURCES变量
#你需要提供src/**/*.c和src/*.c以便GNU make能够包含src目录及其子目录的所有此类文件。
SOURCES=$(wildcard src/**/*.c src/*.c)

#一旦你创建了源文件列表，你可以使用patsubst命令获取*.c文件的SOURCES来创建目标文件的新列表。
#你可以告诉patsubst把所有%.c扩展为%.o，并将它们赋给OBJECTS
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard bin/*.c)
PROGRAMS=$(patsubst %.c,%,$(PROGRAMS_SRC))

TARGET=build/libex1.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests $(PROGRAMS)
dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

#向一个目标提供选项来为当前目标修改它们。这里我通过适用+=语法为库的构建添加了-fPIC
$(TARGET): CFLAGS += -fPIC

#这一真实目标首先创建build目录，之后编译所有OBJECTS。
$(TARGET): build $(OBJECTS)
## $@ $(OBJECTS)语法的意思是，将当前目标的名称放在这里，并把OBJECTS的内容放在后面。
## 这里$@的值为19行的$(TARGET)，它实际上为build/libYOUR_LIBRARY.a。
	ar rcs $@ $(OBJECTS)			
	ranlib $@
$(PROGRAMS): LDLIBS += $(TARGET)

$(SO_TARGET): $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)


build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: LDLIBS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
# The Cleaner
clean:
	rm -rf $(BUILD_DIR) || true
	rm $(OBJECTS) || true
	rm $(TESTS) || true
	rm tests/tests.log || true

