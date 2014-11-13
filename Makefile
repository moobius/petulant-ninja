# Makefile
HSRC  = CDCClient.h \
	    CDCDebug.h \
	    CDCError.h \
	    CDCNode.h \
	    CDCServer.h
CSRC  = CDCClient.c \
	    CDCNode.c \
	    CDCServer.c \
	    main.c
COBJ  = $(CSRC:.c=.o)
EXE   = cdc
GCC   = gcc
FLAGS = -std=c99 -Wall -Wextra -g
JUNK  = $(COBJ)

all: $(EXE)

$(EXE): $(COBJ)
	$(GCC) $(FLAGS) -o$@ $^

%.o: %.c
	$(GCC) $(FLAGS) -c $^

clean:
	rm -rf $(JUNK)
