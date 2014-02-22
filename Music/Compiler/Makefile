CC=gcc
CFLAGS=-Wall
LDLIBS=-lm

BINDIR=bin
SRC=MusicCompiler.c
OBJ=$(patsubst %.c,$(BINDIR)/%.o,$(SRC))

$(BINDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

MusicCompiler: $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

all: MusicCompiler

clean:
	rm $(BINDIR)/*.o
	rmdir $(BINDIR)
	rm MusicCompiler

$(OBJ): | $(BINDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: all clean
