#include<iostream>
using namespace std;

#define ll long long

ll fastModExp(ll a, ll b, ll c){

    ll res = 1;
    while(b>0){

        if(b&1){
            res = (res*a)%c;
        }
        a = (a*a)%c;
        b = b>>1;
    }
    return res;
}

int main() {

	ll a,b,c;
	cin>>a>>b>>c;

    cout<<fastModExp(a,b,c)<<endl;

	return 0;
}
