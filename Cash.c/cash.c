#include <stdio.h>
#include <stdlib.h>
//#include <math.h>



int main(void)
{
    float change;
    int coin[]={25,10,5,1};
    int cents = change * 100;
    int index;
    int amount = 0;
    int e;
    //(change == (change)* 100);


    do
        {

        printf("Enter the change amount:\n");
        scanf("%f", &change);


        }

    while(change <= 0);

//essa parte do codigo precisa ser corrigida, pois não está arredondando
    cents = round(change*100);






    //for(index=0; index < 5; index++)

    //{
           // while(cents - coin[index] >=0 && cents > 0)
         //{
         //        cents = cents - coin[index];
           //     amount++;
         //}
   // }



    printf("%d\n", &cents);


    return 0;
}
