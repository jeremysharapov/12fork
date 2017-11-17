all: forkin.o
	gcc forkin.o

forkin.o: forkin.c
	gcc -c forkin.c

clean:
	rm -f *o *~ a.out

run: all
	./a.out
