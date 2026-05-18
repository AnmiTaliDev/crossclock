CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -Iinclude
SRC = src/main.c src/display.c src/time_util.c
OBJ = $(SRC:.c=.o)
TARGET = crossclock

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
