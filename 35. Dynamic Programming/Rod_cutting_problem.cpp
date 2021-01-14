#include<iostream>
#include<climits>
using namespace std;

//recursive Solution
int max_profitTD(int prices[], int n, int dp[]){
    //base case
    if(n==0){
        return 0;
    }
    ///rec case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        int cut = i+1;

        int current_ans = prices[i] + max_profitTD(prices, n-cut, dp);
        ans = max(ans, current_ans);
    }
    return dp[n] = ans;
}

int max_profitBU(int prices[], int n){

    int dp[n+1];
    dp[0]=0;

    for(int len=1; len<=n; len++){

        int ans=INT_MIN;
        for(int i=0; i<len; i++){
            int cut=i+1;
            int current_ans = prices[i] + dp[len-cut];
            ans = max(current_ans, ans);
        }
        //computed the answer for dp[len]
        dp[len] = ans;
    }

    return dp[n];
}

int main(){

    int prices[] = {3,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);
    int dp[100] = {0};

    // cout<<max_profitTD(prices, n, dp)<<endl;
    cout<<max_profitBU(prices, n)<<endl;

}
