#include<iostream>
using namespace std;

int maxProfitTD(int wines[], int i, int j, int y, int dp[][100]){
    //Base case
    if(i>j){
        return 0;
    }
    // return if dp[i][j] if already present
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    //Rec case
    int opt1 = wines[i]*y + maxProfitTD(wines, i+1, j, y+1, dp);
    int opt2 = wines[j]*y + maxProfitTD(wines, i, j-1, y+1, dp);
    return dp[i][j] = max(opt1, opt2);
}

//Bottom Up
int maxProfitBU(int wines[], int start, int end, int y){
    int dp[100][100] = {0};

    dp[start][start] = 1*wines[start];
    for(int j=start+1; j<=end; j++){
        for(int i=j; i>=0; i--){
            int m = y-(j-i);
            int x = m*wines[j] + dp[i][j-1];
            int y = m*wines[i] + dp[i+1][j];
            dp[i][j] = max(x,y);
        }
    }
    return dp[start][end];
}

int main(){

    int wines[] = {2,3,5,1,4}; //Greedy - > 49 and DP - > 50
    int dp[100][100] = {0};
    int n = sizeof(wines)/sizeof(int);
    int y=5;
    // cout<<maxProfitTD(wines, 0, n-1, y, dp);
    cout<<maxProfitBU(wines, 0, n-1, y);


    return 0;
}
