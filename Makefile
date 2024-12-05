CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

TARGET = mycal
OBJS = mycal.o calendar.o

$(TARGET): $(OBJS)

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)
