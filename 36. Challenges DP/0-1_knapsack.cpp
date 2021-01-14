#include<iostream>
using namespace std;

int knapsack(int size[], int val[], int n, int s, int dp[][100]){
    if(n<0 or s==0){
        return 0;
    }
    if(dp[n][s]!=0){
        return dp[n][s];
    }
    if(size[n]>s){
        return knapsack(size, val, n-1, s, dp);
    }

    int op1 = val[n] + knapsack(size, val, n-1, s-size[n], dp);
    int op2 = knapsack(size, val, n-1, s, dp);
    return dp[n][s] = max(op1, op2);
}

int main(){

    int n, s;
    cin>>n>>s;

    int size[100];
    int val[100];
    for(int i=0; i<n; i++){
        cin>>size[i];
    }
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    int dp[100][100] = {0};
    cout<<knapsack(size, val, n-1, s, dp)<<endl;
    return 0;
}
