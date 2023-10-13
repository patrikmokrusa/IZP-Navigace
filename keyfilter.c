// Patrik Mokruša

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc,char *argv[])
{
  if (argc ==1){
    printf("nezadany parametr\n");
    return 1;
  }

  char txt_file[42][100];
  int len = 0;

  for (int i =0; i < 42; i++){     //nacist <adresy.txt
    
    if (scanf("%s\n",txt_file[i]) == EOF){
      break;
    }
    // printf("%s\n",txt_file[i]);
    len++;
  }

  
  for (int i = 0; i <len; i++){
    for (size_t y =0; y < strlen(txt_file[i]); y++)
    {
      txt_file[i][y]= toupper(txt_file[i][y]);
      // printf("%c",txt_file[i][y]);
    }
    printf("\n");
  }
  
  size_t argcount = strlen(argv[1]);
  for (size_t i = 0; i < argcount ; i++)
  {
    argv[1][i]= toupper(argv[1][i]);
  }

  // for (int i = 0; i < len; i++)     //zjistit jestli tam adrese je primo
  // {
  //   if (argv[1] == txt_file[i])
  //   {
  //     printf("Found: %s",txt_file[i]);
  //     // return 0;
  //   }
    
  // }
  

  char *filtered[42];
  size_t num = 0;
  int num_filtr =0;
  int count = 0;

  for (int i = 0; i < len; i++)
  {
    for (size_t x = 0; x < argcount; x++)
    {
      if (txt_file[i][x] == argv[1][x])
      {
        num++;
      }
      
    }
    if (num == argcount){
      filtered[num_filtr] = txt_file[i];
      // printf("filtered: %s\n",filtered[num_filtr]);
      num_filtr++;
      count++;
    }
    num = 0;
  }
  

  // char filtered[42];                                                              //chelp
  // for (size_t z = 0; z<argcount; z++){ // pocet argumentu
  //   int num = 0;
  //   for (int i = 0; i < len; i++) // pocet radku v txt
  //   {
  //     if (txt_file[i][z] == argv[1][z]) // porovnani s argumentem
  //     {
  //       filtered[num] = txt_file[i];
  //       // printf("filter: %s\n",filtered[num]);
  //       num++;
  //     }
  //   }
  //   int count = 0;
  //   while (txt_file[count][0] !=  '\0')
  //   {
  //     txt_file[count][0] = filtered[count];
  //     count++;
  //     // printf("plsky %s\n",txt_file[count]);
  //   }
  // }
  
  

  printf("Enable: ");
  for (int i = 0; i < count; i++)
  {
    printf("%c",filtered[i][argcount]);
  }
  
  // printf("%d\n",argcount);
  // printf("\nargumenty %s\n",argv[1]);
  // printf("\nPocet mest: %d\n",len);

  // printf("%c\n",*filtered[1]);
  printf("\n");
  return EXIT_SUCCESS;
}
