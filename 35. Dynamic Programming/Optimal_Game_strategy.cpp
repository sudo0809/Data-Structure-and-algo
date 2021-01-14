#include<iostream>
#include<climits>
using namespace std;


int playerScore(int coins[],int start, int end, int dp[][100]){
    if(start==end){
        return coins[start];
    }
    if(start+1==end){
        return max(coins[start], coins[end]);
    }
    //check if the score already exists
    if(dp[start][end]!=0){
        return dp[start][end];
    }

    int maxScore = INT_MIN;
    int left_coin_pick = coins[start] + min(playerScore(coins, start+2, end, dp), playerScore(coins, start+1, end-1, dp));
    int right_coin_pick = coins[end] + min(playerScore(coins, start+1, end-1, dp), playerScore(coins, start, end-2, dp));
    maxScore = max(left_coin_pick, right_coin_pick);
    return dp[start][end] = maxScore;
}

int main(){

    int n;
    cin>>n;
    int coins[100];
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    int dp[100][100] = {0};

    cout<<playerScore(coins, 0, n-1, dp)<<endl;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}
