#include<iostream>
using namespace std;

int gcd(int a, int b){

    // if(b==0){
    //     return a;
    // }
    // else{
    //     return gcd(b, a%b);
    // }

    return b==0? a : gcd(b, a%b);
}

int lcm(int n1, int n2){
    return (n1 * n2)/gcd(n1, n2);
}

int main(){
    int n1,n2;
    cin>>n1>>n2;

    cout<<gcd(n1, n2)<<endl;
    cout<<lcm(n1, n2)<<endl;
    return 0;
}
