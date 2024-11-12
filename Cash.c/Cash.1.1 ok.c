#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    // Declarando as vari�veis
    float change;       // Valor da quantia inserida
    int cents, coins = 0; // Cents para armazenar o valor em centavos e coins para contar as moedas

    // Solicita ao usu�rio para inserir o valor da quantia at� que um valor v�lido (n�o negativo) seja inserido
    do {
        printf("Enter the change amount (positive value):\n");
        scanf("%f", &change);  // L� o valor da quantia em reais (float)
    } while (change < 0); // Garante que o valor seja n�o negativo

    // Convertendo o valor em d�lares para centavos (multiplica por 100 e arredonda)
    cents = round(change * 100);

    // Calculando o n�mero m�nimo de moedas necess�rias
    // Vamos iterar sobre as moedas em ordem de maior valor (25, 10, 5, 1 centavos)

    // Calcula o n�mero de moedas de 25 centavos
    coins += cents / 25;
    cents %= 25; // Atualiza o restante de centavos

    // Calcula o n�mero de moedas de 10 centavos
    coins += cents / 10;
    cents %= 10;

    // Calcula o n�mero de moedas de 5 centavos
    coins += cents / 5;
    cents %= 5;

    // Calcula o n�mero de moedas de 1 centavo
    coins += cents;

    // Imprime o n�mero total de moedas
    printf("Minimum number of coins: %i\n", coins);

    return 0; // Finaliza o programa com sucesso
}
