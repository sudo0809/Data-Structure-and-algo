#include<iostream>
#include<cstring>
using namespace std;

int strToNum(char a[], int n){
    //base case
    if(n==1){
        return (a[n-1] - '0') ;
    }

    //rec case
    return 10*strToNum(a, n-1) + (a[n-1] - '0');
}

int main(){
    char a[10];
    cin>>a;

    int n = strlen(a);

    int num = strToNum(a, n);

    cout<<num<<endl;
}
