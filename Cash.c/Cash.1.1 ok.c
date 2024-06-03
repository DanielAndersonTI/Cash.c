#include <stdio.h>
#include <stdlib.h>
#include <math.h>


    int main(void)
{
    float change;
    int cents, coins = 0;

    do
    {
        printf("Enter the change amount:\n");
        scanf("%f", &change);
    }
    while (change < 0);

    // Convertendo o valor em d�lares para centavos
    cents = round(change * 100);

    // Calculando o n�mero m�nimo de moedas necess�rias
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    // Imprimindo o resultado
    printf("%i\n", coins);
    return 0;
}
