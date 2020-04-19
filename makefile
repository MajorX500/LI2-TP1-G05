SlimeTrail : src/main.o src/data.o src/interface.o src/logic.o src/lists.o src/bot.o
	gcc -o SlimeTrail src/main.o src/data.o src/interface.o src/logic.o src/lists.o src/bot.o

main.o : src/main.c src/data.h src/interface.h
	gcc -c src/main.c

data.o : src/data.c src/data.h
	gcc -c src/data.c

interface.o : src/interface.c src/interface.h src/data.h src/logic.h
	gcc -c src/interface.c

logic.o : src/logic.c src/logic.h src/data.h src/interface.h
	gcc -c src/logic.c

lists.o : src/lists.c src/lists.h
	gcc -c src/lists.c

bot.o : src/bot.c src/bot.h src/lists.h
	gcc -c src/bot.c
