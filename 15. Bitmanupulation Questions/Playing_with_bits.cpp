#include<iostream>
using namespace std;

int countSetBits(int num){
    int set_bits = 0;
    while(num>0){
        if(num&1){
            set_bits++;
        }
        num = num>>1;
    }
    return set_bits;
}

int main() {
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;

        int count = 0;
        for(int j=a; j<=b; j++){
            count += countSetBits(j);
        }

        cout<<count<<endl;
    }
    return 0;
}
