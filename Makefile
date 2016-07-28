CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS) -Iinclude
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=bin/libRomanAPI.a
SOTARGET=$(patsubst %.a,%.so,$(TARGET))

all: $(TARGET) $(SOTARGET)

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SOTARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

	$(CC) -static ./app/RomanCalculator.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/RomanCalculator

	$(CC) -static ./test/TestRange.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/TestRange
	$(CC) -static ./test/TestSequencing.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/TestSequencing
	$(CC) -static ./test/TestTrimming.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/TestTrimming
	$(CC) -static ./test/TestConvertIntToRoman.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/TestConvertIntToRoman
	$(CC) -static ./test/TestRomanToInt.c -Iinclude -Lbin/ -lRomanAPI -o ./bin/TestRomanToInt
	
	#./bin/TestRange
	#./bin/TestSequencing
	#./bin/TestTrimming
	#./bin/TestConvertIntToRoman
	#./bin/TestRomanToInt
	
	checkmk check/ConvertRomanToInt.check > check/ConvertRomanToInt.check.c
	$(CC) -Wall  check/ConvertRomanToInt.check.c -Iinclude -Lbin/ -lRomanAPI -lcheck -o ./bin/ConvertRomanToInt.check.exe
	
	
	
	
build:
	@mkdir -p bin

clean:
	rm -rf $(OBJECTS)

