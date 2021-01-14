#include<iostream>
using namespace std;
//top down approach  
int NoOfBST(int n, int dp[]){
    //base case
    if(n==0 or n==1){
        return 1;
    }
    //chek in the dp if the n was calculated before
    if(dp[n]!=0){
        return dp[n];
    }
    //rec case
    int ans=0;
    for(int i=1; i<=n; i++){
        ans += NoOfBST(i-1, dp)*NoOfBST(n-i,dp);
    }
    return dp[n] = ans;
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<NoOfBST(n, dp)<<endl;
}
