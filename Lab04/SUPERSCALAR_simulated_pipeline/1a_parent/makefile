CC = gcc
LIBDIR = ../lib
CFLAGS = -I. -I$(LIBDIR) -Wall
OBJ = $(SRC:.c=.o)
EXECUTABLE = main.exe
DEPS = $(wildcard $(LIBDIR)/*.h)

SRC = main.c queue_wrapper.c encoder.c readYUV.c $(LIBDIR)/queue.c $(LIBDIR)/mem_info.c

all: $(EXECUTABLE)

cq:
	rm -f ../queues/*

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)