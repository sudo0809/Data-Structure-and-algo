#include<iostream>
using namespace std;

#define ll long long

void prime_seive(int *p){

    p[0] = p[1] = 0;
    p[2] = 1;
    for(ll i=3; i<=1000005; i+=2){
        p[i] = 1;
    }

    for(ll i=3; i<=1000005; i+=2){
        if(p[i] == 1){
            for(ll j=i*i; j<=1000005; j = i+j){
                p[j] = 0;
            }
        }
    }

    return;
}

int main() {

    //In the coding blocks compiler we have to write the value of n
    // everywhere we have used n, and use ll while intializing for loop variables
    // int n = 1000005;
    int p[1000005] = {0};
    prime_seive(p);

    int cumSum[1000005] = {0};
    for(int i=1; i<1000000; i++){
        cumSum[i] = cumSum[i-1] + p[i];
    }

    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<cumSum[b] - cumSum[a-1]<<endl;
    }
    return 0;
}
