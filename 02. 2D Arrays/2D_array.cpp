#include<iostream>
using namespace std;

int main() {

    int a[5][3];
    int m, n;
    cin>> m >> n;
    int val=1;
    //Iterate over array
    for(int row=0;row<=4; row++){
      for(int col=0; col<=2; col++){
        a[row][col] = val;
        val = val + 1;
        cout<< a[row][col]<<" ";
      }
      cout<< endl;
    }
    return 0;
}
