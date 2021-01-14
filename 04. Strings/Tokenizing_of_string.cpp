#include<iostream>
#include<cstring>
using namespace std;

//char *strtok(char *s, char *delimiters)
//returns a token on each subsequent call
//on the first call function shold be passed with string argument for s
//on ubsequent calls we should pass the string argument as well


int main() {

  char s[100] = "Today is a rainy day";

  char *ptr = strtok(s, " ");
  cout<<ptr<<endl;

  while(ptr!= NULL){
    ptr = strtok(NULL, " ");
    cout<<ptr<<endl;
  }
  return 0;

}
