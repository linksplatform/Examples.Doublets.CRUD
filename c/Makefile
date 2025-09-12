CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = crud
SOURCE = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Alternative build with clang
clang: $(SOURCE)
	clang $(CFLAGS) -o $(TARGET) $(SOURCE)