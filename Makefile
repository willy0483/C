CC = gcc
INCDIRS = -I.
OPT = -O0
CFLAGS = -Wall -g $(INCDIRS) $(OPT)

SRCDIR   = src
BUILDDIR = build

CFILES = $(SRCDIR)/main.c
OBJECTS = $(BUILDDIR)/main.o

BINARY = $(BUILDDIR)/origins

all: $(BINARY)

$(BINARY): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(BUILDDIR):
	mkdir $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
