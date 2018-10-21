all : mergeSQ

mergeSQ.o : mergeSQ.c mergeSQ.h
	gcc -c mergeSQ.c

main.o : main.c mergeSQ.h
	gcc -c main.c

mergeSQ : main.o mergeSQ.o

clean :
	rm *.o mergeSQ
