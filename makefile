CC=gcc
INCLUDE=./include
CFLAGS=-I $(INCLUDE) -lm -g -w
DEPS=src/filter.h src/image.h
OBJ=src/main.o src/image.o src/filter.o

%.0: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

heightmap-tools: $(OBJ)
	$(CC) -o $@.out $^ $(CFLAGS)

clean:
	-rm *.o