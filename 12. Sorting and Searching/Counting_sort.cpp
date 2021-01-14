#include<iostream>
using namespace std;

void countSort(int arr[], int n){

    int count_arr[100] = {0};
    int max_idx = 0;
    for(int i=0; i<n; i++){
        if(count_arr[arr[i]] == 0){
            count_arr[arr[i]] = 1;
        }
        else{
            count_arr[arr[i]] += 1;
        }
        max_idx = max(max_idx, arr[i]);
    }

    for(int i=1; i<=max_idx; i++){
        count_arr[i] += count_arr[i-1];
    }

    int output[n];
    for(int i=0; i<n; i++){
        output[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]-- ;
    }
    //
    // for(int i=0; i<=max_idx; i++){
    //     cout<<count_arr[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }

    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    countSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
