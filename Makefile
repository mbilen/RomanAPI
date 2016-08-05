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
	$(CC) -static -Wall  check/ConvertRomanToInt.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/ConvertRomanToInt.check.exe

	checkmk check/TestTrimming.check > check/TestTrimming.check.c
	$(CC) -static -Wall  check/TestTrimming.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/TestTrimming.check.exe

	checkmk check/RangeTest.check > check/RangeTest.check.c
	$(CC) -static -Wall  check/RangeTest.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/RangeTest.check.exe

	checkmk check/RomanToInt.check > check/RomanToInt.check.c
	$(CC) -static -Wall  check/RomanToInt.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/RomanToInt.check.exe

	checkmk check/TestSequence.check > check/TestSequence.check.c
	$(CC) -static -Wall  check/TestSequence.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/TestSequence.check.exe

	checkmk check/Addition.check > check/Addition.check.c
	$(CC) -static -Wall  check/Addition.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/Addition.check.exe

	checkmk check/Subtraction.check > check/Subtraction.check.c
	$(CC) -static -Wall  check/Subtraction.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/Subtraction.check.exe

	checkmk check/IntToRoman.check > check/IntToRoman.check.c
	$(CC) -static -Wall  check/IntToRoman.check.c -Iinclude $(shell pkg-config --cflags check) -Lbin/ -lRomanAPI  $(shell pkg-config --libs check)  -lpthread -lrt -lm -o ./bin/IntToRoman.check.exe

	@echo ======================================================================
	@echo =================	   RUNNING CHECK UNIT TESTS 	====================
	@echo ======================================================================

	./bin/ConvertRomanToInt.check.exe
	./bin/TestTrimming.check.exe
	./bin/RangeTest.check.exe
	./bin/RomanToInt.check.exe
	./bin/IntToRoman.check.exe
	./bin/TestSequence.check.exe
	./bin/Addition.check.exe
	./bin/Subtraction.check.exe
		
	@echo ======================================================================
	@echo DONE
	
	
build:
	@mkdir -p bin

clean:
	rm -rf $(OBJECTS)

