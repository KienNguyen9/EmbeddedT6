CC = gcc
CFLAGS = -Wall

all: main.o message.o
    $(CC) $(CFLAGS) -o my_program main.o message.o

main.o: main.c message.h
    $(CC) $(CFLAGS) -c main.c
message.o: message.c message.h
    $(CC) $(CFLAGS) -c message.c

clean:
    rm -f *.o my_program