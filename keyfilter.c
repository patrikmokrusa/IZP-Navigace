// Patrik Mokruša 
// 19.10.2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void sort(int arr[], int x){
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

void dedouble(int arr[], int x){
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

int main(int argc,char *argv[]){
  char txt_file[42][101];                 //declare list 42 lines, max 100 chars per line (+ '\0')
  int len = 0;

  // for (int i =0; i < 42; i++)         
  // {                
  //   if (scanf("%s\n",txt_file[i]) == EOF){             
  //     break;
  //   }
  //   len++;
  // }
  
  while (scanf("%s\n",txt_file[len]) != EOF){  //input stdin (<adresy.txt) //if EOF stop inputting
    len++;
  }
  

  for (int i = 0; i <len; i++){    //convert list to uppercase                        
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
  
  size_t len_arg = strlen(argv[1]);             //convert argument to uppercase
  
  for (size_t i = 0; i < len_arg ; i++){
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