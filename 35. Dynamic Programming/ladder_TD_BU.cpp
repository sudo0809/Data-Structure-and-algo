#include<iostream>
using namespace std;

//Top down approach O(nk) time and O(n) space
int findWays(int n, int k, int dp[]){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += findWays(n-i, k, dp);
    }
    return dp[n] = ans;
}
//Bottom Up
int ladderBU(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
            }
        }
    }
    //see the Bottom Up using for loop
    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    return dp[n];
}
//ladder space optimized
int ladderBU_Optimised(int n, int k){
    int dp[100] = {0};

    dp[0] = dp[1] = 1;
    for(int i=2; i<=k; i++){
        dp[i] = 2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    //see the Bottom Up using for loop
    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}

int main(){

    int n = 4; //steps in ladder
    int k = 3; //max jumps over steps that are possible
    int dp[100]={0};
    // int ways = findWays(n, k, dp);
    // cout<<ways<<endl;
    cout<<ladderBU_Optimised(n,k)<<endl;

}
