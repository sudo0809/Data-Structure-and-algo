#include<iostream>
using namespace std;
//Brute force
int main(){

  int n;
  cin>>n;

  int a[100][100];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }
  int sum=0;
  //Finding subarray
  //lr = lowest row; lc=lower column
  //br = big row; bc=big column
  for(int lr=0; lr<n; lr++){
    for(int lc=0; lc<n; lc++){
      for(int br=lr; br<n; br++){
        for(int bc=lc; bc<n; bc++){
          for(int i=lr; i<=br; i++){
            for(int j=lc; j<=bc; j++){
              sum = sum + a[i][j];
            }
          }
        }
      }
    }
  }
  cout<<endl;
  cout<<sum;
  return 0;
}
