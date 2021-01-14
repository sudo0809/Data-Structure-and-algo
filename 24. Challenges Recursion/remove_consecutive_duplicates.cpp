#include<iostream>
#include<cstring>
using namespace std;

void withoutConsecativeSame(char a[], int s, int e, int prev){
    // base case
    if(s>=e){
        if(a[s] != prev){
            cout<<a[s];
        }
        return;
    }

    // recursive case
    if(a[s] != prev){
        cout<<a[s];
        prev = a[s];
        withoutConsecativeSame(a, s+1, e, prev);
    }
    else{
        withoutConsecativeSame(a, s+1, e, prev);
    }

}

int main(){
    char a[1000];
    cin>>a;

    cout<<a[0];
    withoutConsecativeSame(a, 1, strlen(a)-1, a[0]);
}
