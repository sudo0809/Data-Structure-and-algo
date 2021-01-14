#include<iostream>
#include<climits>
using namespace std;

int main() {

  int n;
  cin>>n;

  //given a sorted matrix
  int a[100][100];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>a[i][j];
    }
  }
  //for a suffix matrix
  int sufixmatrix[100][100];
  for(int i=n-1; i>=0; i--){
    for(int j=n-1; j>=0; j--){
      if(i==n-1 and j==n-1){
        sufixmatrix[i][j] = a[i][j];
      }
      else if(i==n-1 and j<n-1){
        sufixmatrix[i][j] = sufixmatrix[i][j+1] + a[i][j];
      }
      else if(i<n-1 and j==n-1){
        sufixmatrix[i][j] = sufixmatrix[i+1][j] + a[i][j];
      }
      else{
        sufixmatrix[i][j] = sufixmatrix[i+1][j] + sufixmatrix[i][j+1] + a[i][j] - sufixmatrix[i+1][j+1];
      }
    }
  }
  int max_sum = INT_MIN;
  //printing suffix sum matrix
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<sufixmatrix[i][j]<<" ";
      max_sum = max(max_sum, sufixmatrix[i][j]);
      // if(max_sum<sufixmatrix[i][j]){
      //   max_sum = sufixmatrix[i][j];
      // }
    }
    cout<<endl;
  }

  cout<<max_sum;

  return 0;
}
