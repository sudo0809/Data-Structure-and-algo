#include<iostream>
using namespace std;

//First method
//Time complexity O(log(N) + 1)
int countBits(int n){

    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}

//Second Method
//Time complexity O(no. of set bits)  set bits are '1' in the binary number
int countBitsFast(int n){
    int ans = 0;
    while(n>0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

//Thoird method
// Inbuild method

int main(){

    //Given a Number N, find number of set bits in binary rep. of in
    //N= 13, Binary = 1101, Output = 3

    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;
    //Inbuild method
    cout<<__builtin_popcount(n)<<endl;

    return 0;
}
