#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    int total_xor = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        total_xor = total_xor^a[i];
    }

    int temp = total_xor;
    int pos= 0;
    while((temp&1) != 1){
        pos++;
        temp = temp>>1;
    }

    int mask = (1<<pos);
    int x=0;
    int y=0;
    for(int i=0; i<n; i++){
        if(mask&a[i]){
            x = x^a[i];
        }
    }
    y = total_xor^x;

    cout<<min(x,y)<<" "<<max(x,y)<<endl;
    return 0;
}
