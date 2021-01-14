#include<iostream>
using namespace std;

int BinaryWays(int n, int last_digit, int dp[][2]){
    if(n==1 ){
        return 1;
    }
    //if the n case is already computed
    if(dp[n-1][last_digit]!=0){
        return dp[n-1][last_digit];
    }


    if(last_digit==0){
        return dp[n-1][last_digit] = BinaryWays(n-1, 0, dp) + BinaryWays(n-1, 1, dp);
    }
    return dp[n-1][last_digit] = BinaryWays(n-1, 0, dp);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int dp[100][2] = {0};
        int last_digit_zero = BinaryWays(n,0, dp);
        int last_digit_one = BinaryWays(n,1, dp);
        int total_ways = last_digit_one + last_digit_zero;
        cout<<total_ways<<endl;
    }


    return 0;
}
