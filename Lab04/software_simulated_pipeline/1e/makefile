CC = gcc
CFLAGS = -I. -I../lib -Wall
SRC = main.c queue_wrapper.c ../lib/queue.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = main.exe
DEPS = $(wildcard ../lib/*.h)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)