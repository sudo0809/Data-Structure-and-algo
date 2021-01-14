#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int dp[n] = {0};

    for(int i=0; i<n; i++){
        dp[i]=1; //every element can end at length 1 ..i.e its own length
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                dp[i]= max(dp[i], dp[j]+1);
            }
        }
    }
    int lis = 0;
    for(int i=0; i<n; i++){
        // cout<<dp[i]<<" ";
        lis = max(lis, dp[i]);
    }
    cout<<lis<<endl;

    return 0;
}
