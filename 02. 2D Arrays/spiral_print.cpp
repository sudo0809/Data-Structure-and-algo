#include<iostream>
using namespace std;

void Spiral(int a[][500], int m, int n){
  int startRow = 0;
  int startCol = 0;
  int endRow = m-1;
  int endCol = n-1;

  while(startRow<=endRow and startCol<=endCol){
    //First Row
    for(int i=startCol; i<=endCol; i++){
      cout<< a[startRow][i]<<" ";
    }
    startRow++;
    //Last column
    for(int i = startRow; i<=endRow; i++){
      cout<< a[i][endCol]<<" ";
    }
    endCol--;
    //Last row
    if(endRow > startRow){
      for(int i =endCol;i>=startCol; i--){
        cout<< a[endRow][i]<<" ";
      }
    }
    endRow--;
    //First Column
    if(endCol > startCol){
      for(int i=endRow; i>=startRow; i--){
        cout<< a[i][startCol]<<" ";
      }
    }
    startCol++;
  }

}

int main(){
  int arr[500][500] = {0};
  int m, n;
  cin>>m >> n;

  int val = 1;
  for(int row=0; row<=m-1; row++){
    for(int col=0; col<=n-1; col++){
      arr[row][col] = val;
      val = val + 2;
      cout<<arr[row][col]<<" ";
    }
    cout<<endl;
  }
  Spiral(arr, m , n);

  return 0;
}
