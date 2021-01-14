#include<iostream>
using namespace std;

int Power_recusrion(int x, int p){
    if(p==1){
        return x;
    }

    return (x * Power_recusrion(x, p-1));
}

int Power_bit(int x, int p){
    int ans = 1;

    while(p > 0){
        int last_bit = (p & 1);
        if (last_bit) {
            ans = ans * x;
        }
        x = x * x;
        p = p >> 1;
    }
    return ans;
}

int main(){
    int x,n;
    cin>>x>>n;

    cout<<Power_recusrion(x,n)<<endl;

    cout<<Power_bit(x, n)<<endl;

}
