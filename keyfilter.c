#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int countarr(char ar[42][100]){     //funkce pro ziskani poctu "adres" z pole
    int x=0;
    int element;
    do {
        element = ar[x][0];
        x = x+1;


    }while (element !=0);

    return x-1;

}


int main()
{

  int len = countarr;
 
  
  return EXIT_SUCCESS;
}
