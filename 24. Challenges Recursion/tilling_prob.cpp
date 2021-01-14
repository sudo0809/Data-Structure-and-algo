#include<iostream>
using namespace std;

int findWays(int n, int m){

    if(n < m){
        return 1;
    }

    //rec case
    int x = findWays(n-1, m);
    int y = findWays(n-m, m);

    return x+y;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        // bricks can be placed as mx1 and 1xm
        int ways = findWays(n, m);
        cout<<ways<<endl;
    }
}
