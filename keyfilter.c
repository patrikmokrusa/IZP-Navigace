// Patrik Mokruša

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



int main(int argc,char *argv[])
{
  if (argc <2){                           //if no parameter
    printf("No parameter\n");
    return 1;
  }


  char txt_file[42][101];                 //declare list 42 lines, max 100 chars per line (+ '\0')
  int len = 0;

  for (int i =0; i < 42; i++){                //input stdin
    
    if (scanf("%s\n",txt_file[i]) == EOF){             //if EOF stop inputting
      break;
    }
    len++;
  }

  
  for (int i = 0; i <len; i++){                         //convert list to uppercase
    for (size_t y =0; y < strlen(txt_file[i]); y++)
    {
      txt_file[i][y]= toupper(txt_file[i][y]);
    }
  }
  
  size_t len_arg = strlen(argv[1]);             //convert argument to uppercase
  for (size_t i = 0; i < len_arg ; i++)
  {
    argv[1][i]= toupper(argv[1][i]);
  }


  char *filtered[42];
  size_t num = 0;
  int len_filter =0;
  int count = 0;

  for (int i = 0; i < len; i++)                //if "address" matches argument add it to filtered
  {
    for (size_t x = 0; x < len_arg; x++)
    {
      if (txt_file[i][x] == argv[1][x])
      {
        num++;
      }
    }
    if (num == len_arg){
      filtered[len_filter] = txt_file[i];
      len_filter++;
      count++;
    }
    num = 0;
  }

  
  int found = false;
  if (found == false)                         //check if full argument in filtered
  {
      for (int i = 0; i < len_filter; i++)
    {
      if ((argv[1][len_arg] == '\0') && (filtered[i][len_arg] =='\0'))
      {
        printf("Found: %s",filtered[i]);
        found = true;
      }
    }
  }
  if (len_filter == 0)                 //if nouting filtered
  {
    printf("Not Found");  
  }
  else if(found == false)              //print the next char after argument
  {
    printf("Enable: ");                    
    for (int i = 0; i < count; i++)
    {
      printf("%c",filtered[i][len_arg]);
    }  
  }
  

  // printf("%d\n",len_arg);
  // printf("\nargumenty %s\n",argv[1]);
  // printf("\nPocet mest: %d\n",len);
  // printf("%c\n",*filtered[1]);
  printf("\n");
  return 0;
}
