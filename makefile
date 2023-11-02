CC=gcc
CFLAGS=-I.

# change these to set the proper directories where each file should be
SRCDIR=src
BUILDDIR=build
TARGETDIR=bin

_DEPS = main.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ = main.o 
OBJ = $(patsubst %,$(BUILDDIR)/%,$(_OBJ))

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
    $(CC) -c -o $@ $< $(CFLAGS)

$(TARGETDIR)/main: $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

.PHONY: build
build: $(TARGETDIR)/main

.PHONY: run
run: build
    ./$(TARGETDIR)/main 

.PHONY: clean
clean:
    rm -f $(BUILDDIR)/*.o *~ core $(TARGETDIR)/main