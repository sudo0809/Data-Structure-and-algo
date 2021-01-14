#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(int *p, int n){

    //first mark all odd as 1
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }

    // Sieve
    for(ll i=3; i<=n; i+= 2){
        //if the current number is marked 1 (it is prime)
        if(p[i]==1){
            //mark all the multiple of i as not prime
            for(ll j = i*i; j <= n; j = j+i){
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;

    return ;
}

int main(){
    int t;
    cin>>t;

    // cout<<isPrime(n)<<endl;
    ll n = 1000005;
    int p[n] = {0};
    prime_sieve(p, n);
    int prime[100000];
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(p[i]){
            prime[cnt] = i;
            cnt++;
        }
    }

    //printing all the prime numbers till n
    for(int i=0; i<t; i++){

        int a;
        cin>>a;
        cout<<prime[a-1]<<endl;
    }

    return 0;
}
