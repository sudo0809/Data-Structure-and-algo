#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int dp[n+1];
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }

    for(int i=0; i<n; i++){
        for(int len=0; len<n; len++){
            if(dp[len] < a[i] and a[i]<dp[len+1]){
                dp[len+1] = a[i];
            }
        }
    }

    int lis=0;
    for(int i=0; i<=n ; i++){
        if(dp[i]!=INT_MAX){
            cout<<dp[i]<<endl;
            lis=i;
        }
    }
    cout<<endl;
    cout<<lis<<endl;

    return 0;
}
