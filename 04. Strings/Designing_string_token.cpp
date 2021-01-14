#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str, char delim){
  //string and single char act as a delimiter
  static char *input = NULL;
  if(str!= NULL){
    //this is for the first call
    input = str;
  }
//check for the base case
  if(input==NULL){
    return NULL;
  }

  //start extracting token and store them in an array
  char *output = new char[strlen(input)+1];
  int i=0;
  for( ;input[i]!='\0'; i++){
    if(input[i]!=delim){
      output[i] = input[i];
    }
    else{
      output[i] = '\0';
      input = input + i + 1;
      return output;
    }
  }
  
  //corner case
  output[i] = '\0';
  input = NULL;
  return output;
}


int main() {

  char s[100] = "Today is a rainy day";

  char *ptr = mystrtok(s,' ');
  cout<<ptr<<endl;

  while(ptr!= NULL){
    ptr = mystrtok(NULL,' ');
    cout<<ptr<<endl;
  }
  return 0;

}
