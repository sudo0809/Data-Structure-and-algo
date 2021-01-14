#include<iostream>
using namespace std;
//n frinds can go as a couple or single on a bike
//consider n bikes are present
//find minimum ways
int waysToGo(int n, int dp[]){
    if(n<0){
        return 0;
    }
    if(n==1 or n==0){
        return 1;
    }
    //if the state already exists
    if(dp[n]!=0){
        return dp[n];
    }
    //rec case
    int ans = waysToGo(n-1, dp) + waysToGo(n-2, dp)*(n-1) ;
    return dp[n] = ans;
}

int waysToGoBU(int n){
    int dp[100]={0};
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2]*(i-1);
    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    dp[0] = dp[1] = 1;
    cout<<waysToGo(n, dp)<<endl;
    cout<<waysToGoBU(n)<<endl;
}
