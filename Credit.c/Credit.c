#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fun��es que s�o usadas para validar o n�mero do cart�o.
int num_digitos (long num_cartao);  // Fun��o para contar o n�mero de d�gitos do n�mero do cart�o
int dois_primeiros (long num_cartao, int numeros_de_digitos);  // Fun��o para extrair os dois primeiros d�gitos do n�mero do cart�o
int multiplicar (long num_cartao);  // Fun��o para multiplicar os d�gitos do cart�o de acordo com o algoritmo de Luhn
int somar (long num_cartao);  // Fun��o para somar os d�gitos do cart�o
int valido(int resultado_algoritmo, int dois_primeiros_digitos, int numeros_de_digitos );  // Fun��o para validar se o n�mero do cart�o � v�lido

int main(void)
{
   long num_cartao = 0;

   // Solicita ao usu�rio o n�mero do cart�o de cr�dito
   printf("Digite o numero do Cartao:\n");
   scanf("%d", &num_cartao);  // L� o n�mero do cart�o do usu�rio

   // Chama fun��es auxiliares para obter o n�mero de d�gitos, os dois primeiros d�gitos, o valor da multiplica��o e a soma
   int numeros_de_digitos = num_digitos(num_cartao);
   int dois_primeiros_digitos = dois_primeiros(num_cartao, numeros_de_digitos);
   int multiplicacao = multiplicar(num_cartao);
   int soma = somar(num_cartao);

   // Calcula o resultado final do algoritmo de Luhn
   int resultado_algoritmo = multiplicacao + soma;

   // Chama a fun��o de valida��o para verificar se o cart�o � v�lido
   valido(resultado_algoritmo, dois_primeiros_digitos, numeros_de_digitos);
}

int num_digitos (long num_cartao)
{
    int num_digitos = 0;
    // Conta a quantidade de d�gitos no n�mero do cart�o
    while (num_cartao > 0)
    {
        num_cartao /= 10;  // Remove o �ltimo d�gito do n�mero
        num_digitos++;  // Incrementa o contador de d�gitos
    }
    return num_digitos;  // Retorna o n�mero de d�gitos
}

int dois_primeiros (long num_cartao, int numeros_de_digitos)
{
    // Extrai os dois primeiros d�gitos do n�mero do cart�o
    int dois_primeiros = num_cartao / pow(10, numeros_de_digitos - 2);  // Usa a opera��o de divis�o para isolar os dois primeiros d�gitos
    return dois_primeiros;  // Retorna os dois primeiros d�gitos
}

int multiplicar (long num_cartao)
{
    int multiplicacao = 0;
    int operacao;
    // Aplica o algoritmo de Luhn, multiplicando alternadamente os d�gitos por 2
    while(num_cartao > 0)
    {
        num_cartao /= 10;  // Remove o �ltimo d�gito do n�mero
        operacao = (num_cartao % 10) * 2;  // Multiplica o d�gito por 2
        if (operacao > 9)
        {
            // Se o resultado for maior que 9, soma os d�gitos do n�mero (exemplo: 16 -> 1 + 6)
            operacao = (operacao % 10) + (operacao / 10);
        }
        multiplicacao = operacao + multiplicacao;  // Adiciona ao total da multiplica��o
        num_cartao /= 10;  // Remove o pr�ximo d�gito
    }
    return multiplicacao;  // Retorna o resultado da multiplica��o
}

int somar (long num_cartao)
{
    int soma = 0;
    // Soma os d�gitos restantes do n�mero do cart�o
    while (num_cartao > 0)
    {
        soma = (num_cartao % 10) + soma;  // Soma o �ltimo d�gito
        num_cartao /= 100;  // Remove os dois �ltimos d�gitos
    }
    return soma;  // Retorna a soma
}

int valido(int resultado_algoritmo, int dois_primeiros_digitos, int numeros_de_digitos )
{
    // Verifica se o n�mero do cart�o � v�lido de acordo com o algoritmo de Luhn e os prefixos do cart�o
    if (resultado_algoritmo % 10 == 0)
    {
        // Verifica se o n�mero do cart�o pertence a uma das marcas v�lidas: AMEX, MASTERCARD, ou VISA
        if ((dois_primeiros_digitos == 34 || dois_primeiros_digitos == 37) && (numeros_de_digitos == 15))
        {
            return printf("AMEX\n");  // Se for AMEX, imprime "AMEX"
        }
        else if ((dois_primeiros_digitos >= 51 && dois_primeiros_digitos <= 55) && (numeros_de_digitos == 16))
        {
            return printf("MASTERCARD\n");  // Se for MASTERCARD, imprime "MASTERCARD"
        }
        else if ((dois_primeiros_digitos >= 40 && dois_primeiros_digitos <= 49) && (numeros_de_digitos <= 16 && numeros_de_digitos >= 13))
        {
            return printf("VISA\n");  // Se for VISA, imprime "VISA"
        }
        else
        {
            return printf("INVALIDO\n");  // Se o cart�o n�o pertence a nenhuma das marcas, imprime "INVALIDO"
        }
    }
    else
    {
        return printf("INVALIDO\n");  // Se o algoritmo de Luhn n�o for v�lido, imprime "INVALIDO"
    }
}
