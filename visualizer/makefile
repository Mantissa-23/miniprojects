CC=g++
CFLAGS=-I.
DEPS=
OBJ=main.o

LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

EXEC=./visualizer

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

visualizer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run: clean visualizer
	$(EXEC)

.PHONY: clean

clean:
	rm -rf *.o visualizer
