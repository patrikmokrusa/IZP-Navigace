// Patrik Mokrusa
// 22.10.2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void sort(int arr[], int x){    // sorts array
  int temp;
  for (int i = 0; i < x - 1; i++){
    for (int j = 0; j < x - i - 1; j++){
      if (arr[j] > arr[j + 1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void dedouble(int arr[], int x){     // remove duplicate elements in array
  int temp[x];
  int j = 0;
  for (int i = 0; i < x; i++){
    if (arr[i] != arr[i+1]){
      temp[j++] = arr[i];
    }
  }
  for (int i = 0; i < x; i++){
    if(i < j){
      arr[i] = temp[i];
    }
    else{
      arr[i] = '\0';
    }
  }
}

#define Max_lines 42
#define Max_length 100

int main(int argc,char *argv[]){

  if (argc > 2){                      // if too many arguments return 1
    printf("Too many arguments\n");
    return 1;
  }
  
  char txt_file[Max_lines][Max_length +1];                 // declare list[lines][collums + "\0"]
  int len = 0;

  for (int i =0; i <= Max_lines; i++){         //input stdin (<adresy.txt)                
    if (scanf("%s\n",txt_file[i]) == EOF){     // if EOF break
      break;
    }
    if (strlen(txt_file[i])>Max_length){     // if word is longer than max length return 1
      printf("Error: input too long\n");
      return 1;
    }
    len++;
  }

  if(len == 0){                 // if file is empty return 1
    printf("Error: input file is empty\n");
    return 1;
  }  

  for (int i = 0; i <len; i++){                      //convert list to uppercase                        
    for (size_t y =0; y < strlen(txt_file[i]); y++){
      txt_file[i][y]= toupper(txt_file[i][y]);
    }
  }
  

  if (argc <2){                              //if no parameter
    int sorted[len];
    for (int i = 0; i < len; i++){
      sorted[i]=txt_file[i][0];
    }
    
    sort(sorted,len);
    dedouble(sorted,len);

    printf("Enable: ");
    
    int i = 0;
    while (sorted[i] != '\0'){
      printf("%c",sorted[i]);
      i++;
    }
    printf("\n");
    return 0;
  }

  
  size_t len_arg = strlen(argv[1]);
  
  for (size_t i = 0; i < len_arg ; i++){      //convert argument to uppercase
    argv[1][i]= toupper(argv[1][i]);
  }


  char *filtered[len];
  size_t num = 0;
  int len_filter =0;
  int count = 0;

  for (int i = 0; i < len; i++){                //if "address" matches argument add it to filtered
    for (size_t x = 0; x < len_arg; x++){
      if (txt_file[i][x] == argv[1][x]){
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

  
  bool found = false;
  int sorted[len_filter];

  if (found == false){                         //check if full argument in filtered
    for (int i = 0; i < len_filter; i++){
      if (/*((argv[1][len_arg] == '\0') && (filtered[i][len_arg] =='\0')) ||*/ (len_filter == 1)){
        printf("Found: %s",filtered[i]);
        found = true;
      }
    }
  }

  if (len_filter == 0){                //if nouting filtered
    printf("Not Found");  
  }
  else if(found == false){              //print the next char after argument
    printf("Enable: ");                
    for (int i = 0; i < count; i++){
      sorted[i]=filtered[i][len_arg];
    }  
    sort(sorted, count);
    dedouble(sorted, count);

    for (int i=0; i<count; i++){
      printf("%c",sorted[i]);
    }
  }
  
  printf("\n");
  return 0;
}