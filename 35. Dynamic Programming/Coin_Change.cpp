#include<iostream>
#include<climits>
using namespace std;

int minCoinsTD(int n, int coins[], int T,int dp[]){
    //base case
    if(n==0){
        return 0;
    }
    //Lookup
    if(dp[n]!=0){
        return dp[n];
    }
    //rec case
    int ans = INT_MAX;
    for(int i=0; i<T; i++){
        if(n - coins[i]>=0){
            int subprob = minCoinsTD(n-coins[i], coins, T, dp);
            ans = min(ans,subprob+1);
        }
    }
    return dp[n] = ans;
}

//Min Coins Bottom Up
int minCoinsBU(int n, int coins[], int T){

    int dp[100] = {0};

    for(int i=1; i<=n; i++){
        //Init the current ans as int max
        dp[i] = INT_MAX;
        for(int c=0; c<T; c++){
            if(n-coins[c]>=0){
                int subprob = dp[i-coins[c]];
                dp[i] = min(dp[i] , subprob+1);
            }
        }
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    return dp[n];
}

int main(){

    int n = 15;
    int coins[] = {1,7,10};
    // int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);

    // cout<<minCoinsTD(n, coins, T, dp);
    cout<<minCoinsBU(n, coins, T);

    return 0;
}
