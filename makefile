SlimeTrail : src/Main/main.o src/Data/data.o src/Interface/interface.o src/Logic/logic.o
	gcc -o SlimeTrail src/Main/main.o src/Data/data.o src/Interface/interface.o src/Logic/logic.o

main.o : src/Main/main.c src/Data/data.h src/Interface/interface.h
	gcc -c src/Main/main.c

data.o : src/Data/data.c src/Data/data.h
	gcc -c src/Data/data.c

interface.o : src/Interface/interface.c src/Interface/interface.h src/Data/data.h src/Logic/logic.h
	gcc -c src/Interface/interface.c

logic.o : src/Logic/logic.c src/Logic/logic.h src/Data/data.h src/Interface/interface.h
	gcc -c src/Logic/logic.c

lists.o : src/List/lists.c src/List/lists.h
	gcc -c src/List/lists.c
