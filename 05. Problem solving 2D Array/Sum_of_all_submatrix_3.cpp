#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int a[100][100];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }
  int sum = 0 ;
  //we need to find how many times a particular cell comes into a submatrix
  // arr[i][j]*(no. of possible start cells * no. of possible end cells)
  //no. of possible start cells = (i+1,j+1)-(0,0) +1 is for changing index to human references
  //no.of possible end cells = (n-1,n-1) - (i+1,j+1)
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      sum += a[i][j]*((i+1)*(j+1)*(n-i)*(n-j));
    }
  }
  cout<<sum;

  return 0;
}
