#include<iostream>
using namespace std;

int findIndex(int a[],int s, int e, int *idx, int j, int M){
    // base case
    if(s>=e){
        if(a[s] == M){
            j++;
            idx[j] = s;
        }
        return j;
    }

    // rec case
    if(a[s] == M){
        j++;
        idx[j] = s;
        // cout<<s<<" ";
    }
    return findIndex(a, s+1, e, idx, j, M);
}

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int M;
    cin>>M;

    int idx[n];
    int idx_count = findIndex(a, 0, n-1, idx, -1, M);

    // cout<<endl<<idx_count<<endl;
    for(int i=0; i<=idx_count; i++){
        cout<<idx[i]<<" ";
    }

    return 0;
}
