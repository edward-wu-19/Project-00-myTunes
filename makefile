all: main.o linked.o library.o
	gcc -o main main.o linked.o library.o

main.o: main.c linked.h library.h
	gcc -c main.c

library.o: library.c linked.h
	gcc -c library.c

linked.o: linked.c
	gcc -c linked.c

run:
	./main

clean:
	rm *.o
