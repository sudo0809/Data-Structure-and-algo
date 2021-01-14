#include<iostream>
using namespace std;

#define ll long long

int main() {
    int t;
    cin>>t;

    int primes[] = {2,3,5,7,11,13,17,19};

    while(t--){
        ll n;
        cin>>n;

        ll subsets = (1<<8)-1;
        ll ans = 0;

        for(ll i=0; i<=subsets; i++){
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);

            for(ll j=0; j<7; j++){
                if(i&(1<j)){
                    denom = denom * prime[j];
                }
            }
            if(setBits&1){ //for even no. of bits
                ans += n/denom;
            }
            else{ // for odd no. of bits
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
