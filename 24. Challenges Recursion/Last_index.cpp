#include<iostream>
using namespace std;

int findIndex(int long long a[], int n, int long long M){
    //base case
    if(n==-1){
        return -1;
    }
    if(a[n] == M){
        return n;
    }

    //rec case
    return findIndex(a, n-1, M);
}

int main(){
    int n;
    cin>>n;
    int long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int M;
    cin>>M;

    int idx = findIndex(arr, n-1, M);
    cout<<idx<<endl;

    return 0;
}
