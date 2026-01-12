lab2: main.o vector.o
	gcc main.o vector.o -o lab2

vector.o: vector.c vector.h
	gcc -c vector.c

main.o: main.c vector.h
	gcc -c main.c

clean:
	rm -f *.o lab2