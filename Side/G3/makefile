T3: principal.o desenhos.o
	gcc -o T3 principal.o desenhos.o

principal.o: principal.c desenhos.h
	gcc -c principal.c -lm

desenhos.o: desenhos.c desenhos.h
	gcc -c desenhos.c