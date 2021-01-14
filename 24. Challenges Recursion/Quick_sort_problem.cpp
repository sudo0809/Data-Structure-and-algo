#include<iostream>
using namespace std;

#define ll long long

void quicksort(ll *a, ll s, ll e){
    if(s>=e){
        return;
    }

    int pivot = a[e];
    int run_ptr = s+1; // move forward till the e-1 pos
    int pos_ptr = s; // moves only when swap is done

    while(run_ptr<=e-1){
        if(a[run_ptr]<=pivot){
            swap(a[run_ptr], a[pos_ptr]);
            pos_ptr++;
            run_ptr++;
        }
        else{
            run_ptr++;
        }
    }
    if(a[pos_ptr]>pivot){
        swap(a[pos_ptr], a[e]); //to keep the pivot at correct place
    }

    quicksort(a, s, pos_ptr-1);
    quicksort(a, pos_ptr+1, e);

    return;
}

int main(){

    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr, 0, n-1);

    for(ll i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
