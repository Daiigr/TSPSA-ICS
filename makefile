CC=gcc
CFLAGS=-lm
DEPS = $(shell find ./src -name "*.h")
OBJ = $(patsubst %.c, %.o, $(shell find ./src -name "*.c"))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	@echo 'building...'
	@$(CC) -o TSPSA $^ $(CFLAGS)

run: build
	@echo 'running...'
	./TSPSA

clean:
	@rm -f $(OBJ) TSPSA
