#include<iostream>
using namespace std;

void staircase_search(int a[][100], int n, int key){
//
   int start_point = a[0][n-1];
   int end_col = n-1;
   int row = 0;
   //traversing for the rows i.e for moving downward
   while(row<=n-1 and end_col>=0){
     if(start_point == key){
       cout<<"The key "<<key<<" is present at "<<row+1<<" row and "<<end_col+1<<" colunmn";
       break;
     }
     //when less than key move downward
     else if(start_point < key){
       start_point = a[row+1][end_col];
       row += 1;
     }
     //when greater than key move left
     else {
       start_point = a[row][end_col-1];
       end_col -= 1;
     }
   }
   if(row == n or end_col == -1){
     cout<<"Key "<<key<<" is not present";
   }

 }


int main(){

  int a[100][100];
  int n, key;
  cout<<"Enter the square matrix size "<<endl;
  cin>> n ;
  cout<<"Enter the key "<<endl;
  cin>> key;
  // int a[n][n];
  int val = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      a[i][j] = val;
      val += 1;
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  staircase_search(a, n, key);

  return 0;
}
