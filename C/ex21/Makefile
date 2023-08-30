all:so
	gcc -Wall -g -DNDEBUG src/ex21.c -ldl -o build/ex21


so:
	mkdir build
	gcc -c src/lib21.c -o build/lib21.o
	gcc -shared -o build/lib21.so build/lib21.o

clean:
	rm -rf  build