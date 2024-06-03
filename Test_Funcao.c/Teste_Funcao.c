#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1, valor2, resultado1;

    printf("Digite o primeiro valor: \n");
    scanf("%d", &valor1);
    printf("Digite o segundo valor: \n");
    scanf("%d", &valor2);

    resultado1 = multiplicacao (valor1, valor2);
    printf("O resultado e: %d\n", resultado1);


    printf("Digite o primeiro valor: \n");
    scanf("%d", &valor1);
    printf("Digite o segundo valor: \n");
    scanf("%d", &valor2);

    resultado1 = multiplicacao (valor1, valor2);
    printf("O resultado e: %d\n", resultado1);
    return 0;
}

int multiplicacao (int n1 , int n2)
{
    int resultado;
    resultado = n1 * n2;

    return (resultado);
}
