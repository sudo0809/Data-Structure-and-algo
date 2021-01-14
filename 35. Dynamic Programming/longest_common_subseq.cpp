#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    if(i==s1.length() or j==s2.length()){
        return 0;
    }
    ///check if a state is already computed
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //rec case
    if(s1[i]==s2[j]){
        return dp[i][j] = 1 + lcs(s1, s2, i+1, j+1, dp);
    }
    int opt1 = lcs(s1, s2, i+1, j, dp);
    int opt2 = lcs(s1, s2, i, j+1, dp);
    return dp[i][j] = max(opt1, opt2);
}

int main(){

    string s1 = "ABCD";
    string s2 = "ABEDF";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout<<lcs(s1,s2,0,0, dp)<<endl;
}
