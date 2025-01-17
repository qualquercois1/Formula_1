CFLAGS = -Wall
CC = gcc

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm main $(OBJ)