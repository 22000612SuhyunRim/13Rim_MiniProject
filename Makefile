CC = gcc
CFLAGS = -W -Wall
TARGET = vm
OBJECTS = main.c manager.o k_func.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm *.o vm
