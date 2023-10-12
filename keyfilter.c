// Patrik Mokruša

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// }
// char arr_check(int len, char arr[][100],char y , int x){
//   char filtered;
//   int *fil_num = 0;
//   for (int i = 0; i < x; i++)
//   {
//     if (arr[i][x] == y){
//       filtered[fil_num]= arr[i][x];
//     }
//   }
  


//   return filtered;
// }


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

  int x =0;
  for (int i = 0; i <len; i++){
    for (int y =0; y < strlen(txt_file[i]); y++)
    {
      txt_file[i][y]= toupper(txt_file[i][y]);
      printf("%c",txt_file[i][y]);
    }
    printf("\n");
  }
  
  size_t argcount = strlen(argv[1]);
  for (int i = 0; i < argcount ; i++)
  {
    argv[1][i]= toupper(argv[1][i]);
  }

  char *filtered[42];
  for (int z = 0; z<argcount; z++){
    int num = 0;
    for (int i = 0; i < len; i++)
    {
      if (txt_file[i][z] == argv[1][z])
      {
        filtered[num] = txt_file[i];
        printf("filter: %s\n",filtered[num]);
        num++;
      }
    }
  }
  





  // printf("\n");
  // for (int i = 0; i < 42; i++)
  // {
  //   printf("konecna: %s\n",filtered[i]);
  // }
  
  // printf("%d\n",argcount);
  printf("\nargumenty %s\n",argv[1]);
  // int len = countarr(txt_file);
  printf("\nPocet mest: %d\n",len);

  // printf("%s\n",filtered);
  
  return EXIT_SUCCESS;
}
