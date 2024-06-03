#include <stdio.h>
#include <stdlib.h>

int main(void)
{



    int ni, nf, a;

    do
    {
       printf("Digite o valor inicial da populacao: (Valor a partir de 9)\n", ni);
       scanf("%i", &ni);
    }
    while( ni < 9);

    do
    {
        printf("Digite o valor final da populacao:\n", nf);
        scanf("%i", &nf);
    }
    while( nf < ni);



    for( ni = ni + (ni/3) - (ni/4); ni <= nf;a++)


printf(" O Numero de anos e:%i\n", a);


    return 0;
}
