
HSRC  = 
CSRC  = main.cpp
COBJ  = $(CSRC:.c=.o)
EXE   = a.out
GCC   = g++
FLAGS = -Wall -Wextra
JUNK  = $(COBJ)

all: $(EXE)

$(EXE): $(COBJ)
	$(GCC) $(FLAGS) -o$@ $^

%.o: %.c
	$(GCC) $(FLAGS) -c $^

clean:
	rm -rf $(JUNK)
