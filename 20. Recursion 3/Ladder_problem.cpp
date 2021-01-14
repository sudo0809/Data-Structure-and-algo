#include<iostream>
using namespace std;

int ladder(int n, int k){

    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    //rec case
    // int x = ladder(l-1);
    // int y = ladder(l-2);
    // int z = ladder(l-3);
    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += ladder(n-i, k);
    }
    // return x+y+z;
    return ans;
}

int main() {

    int step, k;
    cin>>step>>k;

    cout<<ladder(step, k)<<endl;

    return 0;
}
