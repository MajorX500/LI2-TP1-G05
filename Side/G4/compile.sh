gcc -c T1.c
gcc -c add.c & gcc -c bye_smol.c & gcc -c shift.c & gcc -c printArray.c
gcc -o ArrayOps T1.o add.o bye_smol.o shift.o printArray.o
