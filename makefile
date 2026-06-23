CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11 -O2
CPPFLAGS := -Isrc

TARGET := build/memory_simulator
SRCS := $(wildcard main.c src/*.c)
OBJS := $(SRCS:%.c=obj/%.o)

.PHONY: all clean fclean re dirs

all: dirs $(TARGET)

dirs:
	mkdir -p build obj

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

obj/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all
