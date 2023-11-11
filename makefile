CC=gcc
CFLAGS=
LDFLAGS=-lm
DEPS = $(shell find ./src -name "*.h")
OBJ = $(patsubst %.c, %.o, $(shell find ./src -name "*.c"))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	@echo 'building...'
	@$(CC) -o TSPSA $^ $(LDFLAGS)

run: build
	@echo 'running...'
	./TSPSA $(ARGS)

clean:
	@rm -f $(OBJ) TSPSA