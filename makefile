CC=gcc
CFLAGS=-I.
DEPS = $(shell find ./src -name "*.h")
OBJ = $(patsubst %.c, %.o, $(shell find ./src -name "*.c"))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o myprog $^ $(CFLAGS)

run: build
	./myprog

clean:
	rm -f $(OBJ) myprog
