#include<iostream>
using namespace std;

void SearchKey(int arr[][100], int n, int key){
  int starti = 0;
  int startj = n-1;
  while(starti < n and startj >=0){
    if(key == arr[starti][startj]){
      cout<<starti<<" row "<<startj<<" column"<<endl;
      return ;
    }
    else if(key>arr[starti][startj]){
      starti = starti + 1;
    }
    else{
      startj = startj - 1;
    }
  }

  if(starti == n and startj < 0){
    cout<<"-1"<<endl;
    return ;
  }
}

int main(){

  int n;
  cin>>n;

  int arr[100][100];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>arr[i][j];
    }
  }

  int key;
  cin>>key;
  SearchKey(arr, n, key);

  return 0;
}
