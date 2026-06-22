CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 -O2

TARGET := build/memory_simulator
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
