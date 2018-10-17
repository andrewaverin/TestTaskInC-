CC=g++
all: hello

hello: main.o Figure.o
	$(CC) main.o Figure.o -o figure

main.o:
	$(CC) -c main.cpp -lopenmp

Figure.o:
	$(CC) -c Figure.cpp

clean:
	rm -rf *.o hello
