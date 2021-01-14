#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;
    int white[100];
    int black[100];
    for(int i=0; i<n; i++){
        cin>>white[i];
    }
    for(int i=0; i<n; i++){
        cin>>black[i];
    }

    sort(white, white+n);
    sort(black, black+n);
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans + abs(black[i] - white[i]);
    }
    cout<<ans<<endl;

    return 0;
}
