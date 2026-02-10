CC = gcc
INCDIRS = -I.
OPT = -O0
CFLAGS = -Wall -g $(INCDIRS) $(OPT)

SRCDIR   = src
BUILDDIR = build

MODULES = node
CFILES = $(SRCDIR)/main.c $(foreach module,$(MODULES),$(wildcard $(SRCDIR)/$(module)/*.c))
OBJECTS = $(patsubst %.c, $(BUILDDIR)/%.o, $(notdir $(CFILES)))
BINARY = $(BUILDDIR)/tree

VPATH = $(dir $(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(BUILDDIR):
	mkdir $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

debug:
	@echo "Source files: $(CFILES)"
	@echo "Object files: $(OBJECTS)"
