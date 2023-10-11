// Patrik Mokruša

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
  if (argc ==1){
    printf("nezadany parametr");
    return 1;
  }
  // char *arg = NULL;
  // strcpy(arg, argv[1];


  char txt_file[42][100];

  for (int i =0; i < 42; i++){     //nacist <adresy.txt
    
    if (scanf("%s\n",txt_file[i]) == EOF){
      break;
    }
    printf("%s\n",txt_file[i]);

  }
  // printf("%c\n",txt_file[0][0]);
  printf("%s\n",txt_file[4]);


  // char txt_file1[42][100]= {"Praha","Brno","Bruntal","Bratislava"};
  
  size_t argcount = strlen(argv[1]);
  // printf("%d\n",argcount);

  int len = countarr(txt_file);








  return EXIT_SUCCESS;
}
