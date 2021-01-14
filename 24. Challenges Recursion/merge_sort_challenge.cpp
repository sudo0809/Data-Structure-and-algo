#include<iostream>
using namespace std;

#define ll long long

void merge(ll *a, ll s, ll e){

    ll mid = (s+e)/2;
    ll i = s; //pointer for 1st sorted array
    ll j = mid+1; // pointer for 2nd sorted array
    ll k=s; // this will point at temp's position
    ll temp[200005];

    while(i<=mid && j<=e){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }

    //copy element of temp to real array
    for(ll i=s; i<=e; i++){
        a[i] = temp[i];
    }
    return;
}

void mergeSort(ll a[], ll s, ll e){
    //base case
    if(s>=e){
        return;
    }

    ll mid = (s+e)/2;
    //rec case
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    //after sorting the two parts merge them
    merge(a,s,e);

    return;
}

int main(){

    ll n;
    cin>>n;
    ll arr[200000];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
