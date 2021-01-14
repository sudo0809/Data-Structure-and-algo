#include<iostream>
using namespace std;
'''
N friends hav to go to party (N bikes available)
they can go on bike either solo or as a couple
Find the number of ways possible to go to party
'''
int ways(int n){
    if (n==1 or n==0){
        return 1;
    }
    if (n==2){
        return 2;
    }
    //rec case
    int solo = ways(n-1);
    // int c = ways(n-2);
    int couple = (n-1) * ways(n-2);

    return solo + couple;
}

int main(){
    // N is the number of friends want to go to party
    int n;
    cin>>n;

    cout<<ways(n)<<endl;
    return 0;
}
