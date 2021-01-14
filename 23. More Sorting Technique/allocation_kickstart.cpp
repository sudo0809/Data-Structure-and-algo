#include<iostream>
#include<algorithm>
using namespace std;

#define int long long

const int N = 1e5 +  5;
int n, b;
int a[N];
int32_t main(){

/*
3
4 100
20 90 40 90
4 50
30 30 10 10
3 300
999 999 999
*/
    int t;
    cin>>t;
    int tc = 0;
    while(t--){
        tc++;
        cin >> n >>b;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        sort(a+1, a+n+1);
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(b >= a[i]){
                ans++;
                b -= a[i];
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }


}
