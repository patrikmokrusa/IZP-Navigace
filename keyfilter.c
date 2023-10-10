#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countarr(char ar[42][100]){     //funkce pro ziskani poctu "adres" z pole
    int x=0;
    int element;
    do {
        element = ar[x][0];
        x = x+1;


    }while (element !=0);

    return x-1;

}


int main(int argc,char *argv[])
{
  // char *arg = NULL;
  // strcpy(arg, argv[1];


  char txt_file[42][100];   
  scanf("%s\n",&txt_file[0]);
  scanf("%s\n",&txt_file[1]);     //nacist <adresy.txt

  printf("%s\n",txt_file[0]);
  printf("%s\n",txt_file[1]);



  char txt_file1[42][100]= {"Praha","Brno","Bruntal","Bratislava"};
  int argcount = strlen(argv[1]);

  printf("%d\n",argcount);

  int len = countarr(txt_file1);

  if (argc == 1){                                  //pokud nezadam parametr
    printf("nezadany parametr");
    return 1;
  }





  return EXIT_SUCCESS;
}
