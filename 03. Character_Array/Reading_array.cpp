#include<iostream>
using namespace std;

void readline(char a[], int maxLen, char delim='\n'){

  int i =0;
  char ch = cin.get();
  while(ch != delim){
    a[i] = ch;
    i++;
    if(i == (maxLen - 1)){
      break;
    }
    ch = cin.get();
  }
  //once out of the loop
  a[i] = '\0';
  return;
}

int main() {
  char a[1000];
  //fuction to read sentence or paragraph eith an ending character
  //readline(a, 1000, '$');
  //inbuild function for the required thing
  cin.getline(a, 1000, '$');
  cout<< a << endl;

  return 0;
}
