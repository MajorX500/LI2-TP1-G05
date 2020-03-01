#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomRange(int);
int sum(int, int);
int sub(int, int);
int mult(int, int);
int divi(int, int);
void correctA();
void wrongA();

void main ()
{
    while (1)
    {
        int x, y, difficulty, op, result, answer;
        srand(time(NULL));
        printf ("Selecione a dificuldade\n (1) Fácil\n (2) Médio\n (3) Difícil\n");
        scanf ("%d", &difficulty);
        printf ("Escolha o tipo de questão aritmética:\n (1) Soma\n (2) Subtração\n (3) Multipplicação\n (4) Divisão\n");
        scanf ("%d", &op);
        while (1)
        {
            x = randomRange(difficulty);
            y = randomRange(difficulty);

            {
                do
                {
                    if (op == 1)
                        result = sum(x, y);
                    if (op == 2)
                        result = sub(x, y);
                    if (op == 3)
                        result = mult(x, y);
                    if (op == 4)
                        result = divi(x, y);
                    scanf ("%d", &answer);
                    if (result != answer)
                        wrongA();
                } while (result != answer);
                correctA();
            }
        }
    }
}

int randomRange(int difficulty)
{
    int lower, upper;
    if (difficulty == 1)
    {
        lower = 0;
        upper = 10;
    }
    if (difficulty == 2)
    {
        lower = 10;
        upper = 100;
    }
    if (difficulty == 3)
    {
        lower = 100;
        upper = 1000;
    }
    return ((rand() % (upper - lower)) + lower);
}

int sum(int x, int y)
{
    printf ("Quanto é %d mais %d?\n", x, y);
    return (x + y);
}

int sub(int x, int y)
{
    printf ("Quanto é %d menos %d?\n", x, y);
    return (x - y);
}

int mult(int x, int y)
{
    printf ("Quanto é %d vezes %d?\n", x, y);
    return (x * y);
}

int divi(int x, int y)
{
    printf ("Quanto é %d a dividir por %d?\n", x, y);
    return (x / y);
}

void correctA()
{
    int n;
    n = random() % 4;
    if (n == 0)
        printf ("Muito bem!\n\n");
    if (n == 1)
        printf ("Óptimo!\n\n");
    if (n == 2)
        printf ("Belo trabalho!\n\n");
    if (n == 3)
        printf ("Continue assim!\n\n");
}

void wrongA()
{
    int n;
    n = random() % 3;
    if (n == 0)
        printf ("Errado, tente novamente.\n\n");
    if (n == 1)
        printf ("Não desista!\n\n");
    if (n == 2)
        printf ("Não, tente mais uma vez.\n\n");
}
