CC = gcc
CFLAGS = -W -Wall
TARGET = VendingMachine
OBJECTS = main.c manager.o k_func.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o VendingMachine
