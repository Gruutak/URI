objects := $(patsubst %.c,%.o,$(wildcard *.c))

main: $(objects)
	gcc $(objects) -o main -lm