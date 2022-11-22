CC=gcc
CFLAGS=-I.
DEPS = vetor.h
OBJ = main.o vetor.o 
EXEC = TADvetor

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core