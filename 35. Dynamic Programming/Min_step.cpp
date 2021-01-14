#include<iostream>
#include<climits>
using namespace std;

int minStepTD(int n, int dp[]){
    //base case
    if(n==1){
        return 0;
    }
    //rec case
    //lookup if n is already computed
    if(dp[n]!=0){
        return dp[n];
    }
    //compute if dp[n] is not known
    int opt1,opt2,opt3;
    opt1 = opt2 = opt3 = INT_MAX;

    if(n%3==0){
        opt1 = minStepTD(n/3, dp);
    }
    if(n%2==0){
        opt2 = minStepTD(n/2, dp);
    }
    opt3 = minStepTD(n-1, dp);

    int ans = min(opt1, min(opt2,opt3)) + 1;
    return dp[n] = ans;
}

int minStepBU(int n){
    //Bottom Up approach
    int dp[100] = {0};
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        int opt1,opt2,opt3;
        opt1 = opt2 = opt3 = INT_MAX;

        if(i%3==0){
            opt1 = dp[i/3]+1;
        }
        if(i%2==0){
            opt2 = dp[i/2]+1;
        }
        opt3 = dp[i-1]+1;

        dp[i] = min(opt1, min(opt2,opt3));
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    // cout<<minStepTD(n, dp);
    cout<<minStepBU(n);
}
