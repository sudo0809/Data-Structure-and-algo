#include<iostream>
#include<algorithm>
using namespace std;

void display(int a[][100], int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}

void rotate(int arr[][100], int n){

  //to mirror the matrix
  for(int row=0; row<n; row++){
    int start_col = 0;
    int end_col = n-1;
    while(start_col<end_col){
      swap(arr[row][start_col], arr[row][end_col]);
      start_col++;
      end_col--;
    }
  }

  //to rotate the matrix
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<j){
        swap(arr[i][j], arr[j][i]);
      }
    }
  }
}

void rotate_stl(int a[][100], int n){

  //Same thing using reverse stl method reverse(start_container, end_container)
  for(int i=0; i<n; i++){
    reverse(a[i], a[i]+n);
  }
  //to rotate the matrix
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<j){
        swap(a[i][j], a[j][i]);
      }
    }
  }
}


int main(){
  int a[100][100];
  int n;
  cin >> n;

  int val = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      //For user input
      //cin >> a[i][j];
      a[i][j] = val;
      cout<<a[i][j]<<" ";
      val += 1;
    }
    cout<<endl;
  }
  cout<<"----------------------"<<endl;
  rotate_stl(a, n);
  display(a, n);
}
