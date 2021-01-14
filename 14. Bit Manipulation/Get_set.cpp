#include<iostream>
using namespace std;

bool isOdd(int n){
    return (n & 1);
}

int getBit(int n, int i){
    int mask = (1 << i);
    int bit = (mask & n)>0 ? 1:0;
    return bit;
}

int setBit(int &n, int i){
    int mask = (1 << i);
    int ans = (n|mask);
    return ans;
}

 void clearBit(int &n, int i){
    int mask = ~(1<<i);
    n = mask&n;
 }

 void updateBit(int &n, int i, int v){
    int mask = ~(1<<i);
    int cleared_n = n&mask;
    n = cleared_n|(v<<i);
 }

int main(){
    int n = 5;
    int i ;
    // cin>>i;

    // cout<<isOdd(n)<<endl;
    // cout<<getBit(n, i)<<endl;
    // n = setBit(n, i);
    // cout<<"Ans "<<n<<endl;
    // clearBit(n,i);

    updateBit(n,2,0);
    updateBit(n, 3,1);
    cout<<n<<endl;
    return 0;
}
