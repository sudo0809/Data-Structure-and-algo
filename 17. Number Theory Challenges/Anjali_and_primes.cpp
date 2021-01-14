#include<iostream>
#include<vector>
using namespace std;

#define ll long long

void prime_seive(ll *p, ll n, ll num){

    p[0] = p[1] = 0;
    p[2] = 1;

    for(ll i=3; i<=n; i += 2){
        p[i] = 1;
    }

    vector<int> primes ;
    primes.push_back(2);
    for(ll i=3; i<=n; i+= 2){

        if(p[i]==1){
            for(ll j=i*i; j<=n; j=j+i){
                p[j] = 0;
            }
            primes.push_back(i);
        }
    }

	cout<<primes[num-1]<<endl;
    return ;
}

int main() {

    ll n;
    cin>>n;

    // ll l = 1000000000;
	ll l = 1000000;
    ll primes_idx[l] = {0};
    prime_seive(primes_idx, l, n);

    // cout<<primes[n-1]<<endl;
}
