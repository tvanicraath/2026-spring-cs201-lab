lab4: q2.o vector.o
	gcc q2.o vector.o -o lab4

vector.o: vector.c vector.h
	gcc -c vector.c

q2.o: q2.c vector.h
	gcc -c q2.c

clean:
	rm -f *.o lab4

pdf:
	pandoc readme.md  --defaults=style.yaml -o lab-4.pdf