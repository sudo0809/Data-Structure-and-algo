#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int longestCommonSub(string s1, string s2){
    //bottom up approach to lcs
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    //1,1....n1, n2
    for(int i=1; i<=n1;i++){
        for(int j=1; j<=n2; j++){

            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1, op2);
            }
        }
    }

    vector<char> result;
    int i=n1, j=n2;
    while(i!=0 and j!=0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]){
            i--;
        }
        else{
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(), result.end());
    for(char x:result){
        cout<<x;
    }

    return dp[n1][n2];
}


int main(){

    string A;
    string B;
    cin>>A>>B;

    int len = longestCommonSub(A,B);

    return 0;
}
