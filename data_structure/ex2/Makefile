all:so
	gcc -Wall -g -DNDEBUG  tests/list_tests.c build/list.so -ldl -o build/list_tests 


so:
	mkdir build
	gcc -c src/list.c  -lpthread -o build/list.o -fPIC
	gcc -shared -o  build/list.so build/list.o 

clean:
	rm -rf  build

