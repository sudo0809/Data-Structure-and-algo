#include<iostream>
using namespace std;

int min_cost(int R, int C, int cost[][100]){

    int dp[100][100] = {0};

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){

            //base case
            if(i==0 and j==0){
                dp[i][j] = cost[0][0];
            }
            else if(i==0){
                dp[i][j] = dp[i][j-1] + cost[0][j];
            }
            else if(j==0){
                dp[i][j] = dp[i-1][j] + cost[i][0];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
            }
        }
    }
    return dp[R-1][C-1];
}

int main(){

    int cost[100][100];
    int R, C;
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>cost[i][j];
        }
    }

    cout<<min_cost(R,C, cost)<<endl;
}
