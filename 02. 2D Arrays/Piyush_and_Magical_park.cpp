#include<iostream>
using namespace std;

void magical_park(char a[][100], int m, int n, int k, int s){

 //'.' = reduce 2
 //'*' = increase 5
 //'#' = block
 //Use below input for the question

 // . . * .
 // . * . .
 // . # . . 
 //  * * . .

 // Every step reduce 1
 //piyush can get out of the park
 bool success = true;

 for(int i=0; i<m; i++){
   for(int j=0; j<n; j++){
     char ch = a[i][j];

     if(s<k){
       success = false;
       break;
     }
     else if(ch=='*'){
       s = s + 5;
     }
     else if(ch=='.'){
       s = s - 2;
     }
     else{
       break;
     }
     //we also loose 1 point when we move right except for the last columns
     if(j!=n-1){
       s -= 1;
     }
   }
 }
 if(success){
   cout<<"Yes"<<endl;
   cout<<s<<endl;
 }
 else{
   cout<< "No" <<endl;
 }
}

int main() {
  int m, n, k, s;
  cin>> m >> n >> k >> s;

  char park[100][100];
  //Take Input
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin>> park[i][j];
    }
  }
  magical_park(park, m, n, k, s);

  return 0;
}
