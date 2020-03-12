gcc -Wall -c main.c
gcc -Wall -c data.c & gcc -Wall -c interface.c & gcc -Wall -c logic.c
gcc -Wall -o SlimeTrail main.o data.o interface.o logic.o
