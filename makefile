all: main.o linked.o library.o
	gcc -o main main.o linked.o library.o

main.o: main.c linked.h library.h
	gcc -x c -c main.c

library.o: library.c library.h linked.h
	gcc -x c -c library.c

linked.o: linked.c linked.h
	gcc -x c -c linked.c

run:
	./main

clean:
	rm *.o
