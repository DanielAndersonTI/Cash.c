#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções que são usadas para validar o número do cartão.
int num_digitos (long num_cartao);  // Função para contar o número de dígitos do número do cartão
int dois_primeiros (long num_cartao, int numeros_de_digitos);  // Função para extrair os dois primeiros dígitos do número do cartão
int multiplicar (long num_cartao);  // Função para multiplicar os dígitos do cartão de acordo com o algoritmo de Luhn
int somar (long num_cartao);  // Função para somar os dígitos do cartão
int valido(int resultado_algoritmo, int dois_primeiros_digitos, int numeros_de_digitos );  // Função para validar se o número do cartão é válido

int main(void)
{
   long num_cartao = 0;

   // Solicita ao usuário o número do cartão de crédito
   printf("Digite o numero do Cartao:\n");
   scanf("%d", &num_cartao);  // Lê o número do cartão do usuário

   // Chama funções auxiliares para obter o número de dígitos, os dois primeiros dígitos, o valor da multiplicação e a soma
   int numeros_de_digitos = num_digitos(num_cartao);
   int dois_primeiros_digitos = dois_primeiros(num_cartao, numeros_de_digitos);
   int multiplicacao = multiplicar(num_cartao);
   int soma = somar(num_cartao);

   // Calcula o resultado final do algoritmo de Luhn
   int resultado_algoritmo = multiplicacao + soma;

   // Chama a função de validação para verificar se o cartão é válido
   valido(resultado_algoritmo, dois_primeiros_digitos, numeros_de_digitos);
}

int num_digitos (long num_cartao)
{
    int num_digitos = 0;
    // Conta a quantidade de dígitos no número do cartão
    while (num_cartao > 0)
    {
        num_cartao /= 10;  // Remove o último dígito do número
        num_digitos++;  // Incrementa o contador de dígitos
    }
    return num_digitos;  // Retorna o número de dígitos
}

int dois_primeiros (long num_cartao, int numeros_de_digitos)
{
    // Extrai os dois primeiros dígitos do número do cartão
    int dois_primeiros = num_cartao / pow(10, numeros_de_digitos - 2);  // Usa a operação de divisão para isolar os dois primeiros dígitos
    return dois_primeiros;  // Retorna os dois primeiros dígitos
}

int multiplicar (long num_cartao)
{
    int multiplicacao = 0;
    int operacao;
    // Aplica o algoritmo de Luhn, multiplicando alternadamente os dígitos por 2
    while(num_cartao > 0)
    {
        num_cartao /= 10;  // Remove o último dígito do número
        operacao = (num_cartao % 10) * 2;  // Multiplica o dígito por 2
        if (operacao > 9)
        {
            // Se o resultado for maior que 9, soma os dígitos do número (exemplo: 16 -> 1 + 6)
            operacao = (operacao % 10) + (operacao / 10);
        }
        multiplicacao = operacao + multiplicacao;  // Adiciona ao total da multiplicação
        num_cartao /= 10;  // Remove o próximo dígito
    }
    return multiplicacao;  // Retorna o resultado da multiplicação
}

int somar (long num_cartao)
{
    int soma = 0;
    // Soma os dígitos restantes do número do cartão
    while (num_cartao > 0)
    {
        soma = (num_cartao % 10) + soma;  // Soma o último dígito
        num_cartao /= 100;  // Remove os dois últimos dígitos
    }
    return soma;  // Retorna a soma
}

int valido(int resultado_algoritmo, int dois_primeiros_digitos, int numeros_de_digitos )
{
    // Verifica se o número do cartão é válido de acordo com o algoritmo de Luhn e os prefixos do cartão
    if (resultado_algoritmo % 10 == 0)
    {
        // Verifica se o número do cartão pertence a uma das marcas válidas: AMEX, MASTERCARD, ou VISA
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
            return printf("INVALIDO\n");  // Se o cartão não pertence a nenhuma das marcas, imprime "INVALIDO"
        }
    }
    else
    {
        return printf("INVALIDO\n");  // Se o algoritmo de Luhn não for válido, imprime "INVALIDO"
    }
}
