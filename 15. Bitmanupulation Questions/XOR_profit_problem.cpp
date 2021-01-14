#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin>>x>>y;

    int max_XOR = 0;
    for(int i=x; i<=y; i++){
        for(int j=i+1; j<=y; j++){
            max_XOR = max(max_XOR, (i^j));
        }
    }
    cout<<max_XOR<<endl;

    return 0;
}
