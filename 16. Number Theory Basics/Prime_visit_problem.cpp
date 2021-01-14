#include<iostream>
using namespace std;
#define ll long long

void prime_sieve(int *p){

    //first mark all odd as 1
    for(int i=3; i<=1005; i+=2){
        p[i] = 1;
    }

    // Sieve
    for(ll i=3; i<=1005; i+= 2){
        //if the current number is marked 1 (it is prime)
        if(p[i]==1){
            //mark all the multiple of i as not prime
            for(ll j = i*i; j <= 1005; j = j+i){
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;

    return ;
}

int main(){

    int n = 1005;
    int p[1005] = {0};
    prime_sieve(p);

    int cumSum[1005] = {0};

    //precompute the prime number in the cumSum
    for(int i=1; i<1005; i++){
        cumSum[i] = cumSum[i-1] + p[i];
    }
    int q; // number of queries
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<cumSum[b] - cumSum[a-1];
    }

    return 0;
}
