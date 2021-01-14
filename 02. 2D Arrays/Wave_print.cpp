#include<iostream>
using namespace std;
int main(){
    int a[100][100] = {0};
    int m, n;
    cin>> m >> n;
    int val =1;

    for(int row=0;row<=m-1;row++){
      for(int col=0; col<=n-1; col++){
        a[row][col] = val;
        val = val+ 3;
        cout<< a[row][col]<< " ";
      }
      cout<<endl;
    }

    //Wave print
    for(int col=0; col<=n-1; col++){
      //for even columns Top Down
      if(col%2 == 0){
        for(int row=0; row<=m-1; row++){
          cout<<a[row][col]<<" ";
        }
      }
      //for odd columns Bottom Up
      else{
        for(int row=m-1; row>=0; row--){
          cout<<a[row][col]<<" ";
        }
      }


    }
}
