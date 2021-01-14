#include<iostream>
using namespace std;

int main(){

  int a[] = {1, 2, 3};
  cout<< a<< endl;

  char b[] = {'a', 'b', 'c', '\0'};
  cout<< b << endl;

  char s1[] = {'h', 'e', 'l', 'l', 'o'}; //here null character'\0' is not present so can add garbage value
  char s2[] = "hello";

  cout<< s1 << " " << sizeof(s1) <<endl; //5 bytes
  cout<< s2 << " " << sizeof(s2) <<endl; //6 bytes

  char c[10] = "hello" //hear max string length is 10

  return 0;
}
