#include<iostream>
#include<cstring>
using namespace std;

void display(char a[], int s, int e){
    //base case
    if(s>=e){
        cout<<a[s];
        return;
    }

    //rec case
    if(a[s+1] != a[s]){
        cout<<a[s];
        display(a, s+1, e);
    }
    else{
        cout<<a[s]<<"*";
        display(a, s+1, e);
    }

    return;
}

int main(){
    char a[1000];
    cin>>a;

    display(a, 0, strlen(a)-1);

    return 0;
}
