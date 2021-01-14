#include<iostream>
using namespace std;

//top down approach O(N) time and  O(N) space
int fib(int n, int dp[]){
    //Base case
    if(n==0 or n==1){
        return n;
    }
    //recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans ;
    ans  = fib(n-1, dp) + fib(n-2,dp);
    return dp[n] = ans;
}

//bottom up approach O(N) time and  O(N) space
int fibBU(int n){
    int dp[100] = {0};
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//bottom Up approach with space optimization
int fibSpaceOpt(int n){
    if(n==0 or n==1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i=2; i<=n; i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){

    int dp[100] = {0};
    int n;
    cin>>n;

    // cout<<fib(n,dp)<<endl;
    // cout<<fibBU(n)<<endl;
    cout<<fibSpaceOpt(n)<<endl;
}
