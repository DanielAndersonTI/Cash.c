#include <stdio.h>
#include <stdlib.h>
#include <time.h>





int main()
{
int array[10][10];
int linha, coluna, soma = 0;

srand(time(NULL));

for (linha = 0; linha < 10; linha++)
    {
    for(coluna = 0; coluna < 10; coluna++)
        array[linha][coluna] = 1 + rand () % 100;
        //printf("\n  \n");
//scanf("%d", &array[linha][coluna]);
    }
for (linha = 0; linha < 10; linha++)
    {
    for(coluna = 0; coluna < 10; coluna++)
    {
        //printf("%d", array[linha][coluna]);
     if (coluna < 9)
     {
       printf("%d" " ", array[linha][coluna] );
     }
     else
     {
        printf("%d" "\n", array[linha][coluna]);
     }
    }

    }
for (linha = 0; linha < 10; linha++)
    {
    for(coluna = 0; coluna < 10; coluna++)
       {
        soma += array[linha][coluna];
       }


    }


    printf("\n\n");
    printf("A soma de todos os numero e: %d", soma);
    printf("\n\n");


//printf("%d", array[linha][coluna]);


    return 0;
}
