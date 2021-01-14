#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp){
    if(i==s1.length() or j==s2.length() or k==s3.length()){
        return 0;
    }
    ///check if a state is already computed
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    //rec case
    if(s1[i]==s2[j] and s2[j]==s3[k]){
        return dp[i][j][k] = 1 + lcs(s1, s2, s3, i+1, j+1, k+1, dp);
    }
    int opt1 = lcs(s1, s2, s3, i+1, j, k, dp);
    int opt2 = lcs(s1, s2, s3, i, j+1, k, dp);
    int opt3 = lcs(s1, s2, s3, i, j, k+1, dp);
    return dp[i][j][k] = max(opt1, max(opt2, opt3));
}

int main(){

    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));

    cout<<lcs(s1,s2,s3,0,0,0,dp)<<endl;
}
