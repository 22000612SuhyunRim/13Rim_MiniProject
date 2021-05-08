CC = gcc
CFLAGS = -W -Wall
TARGET = VendingMachine
OBJECTS = main.c manager.o
all : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o VendingMachine
