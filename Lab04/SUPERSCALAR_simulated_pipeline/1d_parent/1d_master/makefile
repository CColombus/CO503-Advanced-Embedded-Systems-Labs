CC = gcc
LIBDIR = ../../lib
CFLAGS = -I. -I$(LIBDIR) -Wall
SRC = main.c queue_wrapper.c $(LIBDIR)/queue.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = main.exe
DEPS = $(wildcard $(LIBDIR)/*.h)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)