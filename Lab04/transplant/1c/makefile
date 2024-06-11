CC = gcc
CFLAGS = -Wall -Wextra
SRC = main.c queue_wrapper.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXECUTABLE)