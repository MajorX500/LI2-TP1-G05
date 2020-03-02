#include <stdio.h>

void imprime_triangulo(int n)
{
    int x = 0, y = 1, c = 1, s = 0;
    char l = 'A';
    while (y != n + 1)
    {
        while (s != 2 * (n - y))
        {
            printf(" ");
            s ++;
        }
        s = 0;
        while (x != c)
        {
            printf(" %c", l);
            x ++;
            if (c >= x + y)
                l ++;
            else
                l --;
        }
        printf("\n");
        y ++;
        x = 0;
        l = 'A';
        c = c + 2;
    }
}

void imprime_losango(int n)
{
    int x = 0, y = n - 1, c = 2 * n - 3, s = n + 1;
    char l = 'A';
    imprime_triangulo(n);
    while (y != 0)
    {
        while (s != 2 * y - n + 1)
        {
            printf(" ");
            s --;
        }
        s = n + 1;
        while (x != c)
        {
            printf(" %c", l);
            x ++;
            if (c >= x + y)
                l ++;
            else
                l --;
        }
        printf("\n");
        y --;
        x = 0;
        l = 'A';
        c = c - 2;
    }
}

void imprime_hexagono(int n)
{
    int x = 0, y = 1, c = n, s = 0;
    while (y != n + 1)
    {
        while (s != n - y + 1)
        {
            printf(" ");
            s ++;
        }
        s = 0;
        while (x != c)
        {
            if (x == 0 || x == c - 1 || y == 1)
                printf("#");
            else 
                printf(" ");
            x ++;
        }
        printf("\n");
        y ++;
        x = 0;
        c = c + 2;
    }
    c = c - 4;
    y = y - 2;
    s = n + 1;
    while (y != 0)
    {
        while (s != y)
        {
            printf(" ");
            s --;
        }
        s = n + 1;
        while (x != c)
        {
            if (x == 0 || x == c - 1 || y == 1)
                printf("#");
            else 
                printf(" ");
            x ++;
        }
        printf("\n");
        y --;
        x = 0;
        c = c - 2;
    }
}