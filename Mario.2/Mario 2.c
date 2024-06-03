#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, l, c,d, e;


    do
{
       printf("Digite um valor inteiro entre 1 e 8:\n");
       scanf("%d", &a);


}

    while( a < 1 || a > 8);
      {
      for(int l = 0; l < a; l++)
        {
            for(int e = 0; e < (a - l - 1); e++)
            {
                printf(" ");
            }
            for(int c = 0; c <= l; c++ )
            {
                printf("#");
            }

            printf("  ");

            for(int c = 0; c <= l; c++)
            {
                printf("#");
            }

            printf("\n");

        }
     }





    return 0;
}
