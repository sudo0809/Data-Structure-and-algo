#include<iostream>
using namespace std;
#define ll long long

int knapsack(ll size[], ll val[], int n, int s, ll dp[100]){
    if(n<0 or s==0){
        return 0;
    }
    if(dp[s]!=0){
        return dp[s];
    }
    ll op1 = 0;
    ll op2 = 0;
    if(size[n]<=s){
        op1 = val[n] + knapsack(size, val, n, s-size[n], dp);
    }
    op2 = knapsack(size, val, n-1, s, dp);


    return dp[s] = max(op1, op2);
}

int main(){

    int n, s;
    cin>>n>>s;

    ll size[100];
    ll val[100];
    for(int i=0; i<n; i++){
        cin>>size[i];
    }
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    ll dp[100] = {0};
    cout<<knapsack(size, val, n-1, s, dp)<<endl;
    return 0;
}
