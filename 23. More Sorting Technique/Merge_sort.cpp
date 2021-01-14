#include<iostream>
using namespace std;

int cnt=0;
void merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k=s;
    int temp[100] ;
    while(i<=mid and j<=e){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    //we need to copy all sorted element to original array
    for(int i=0; i<=e; i++){
        a[i] = temp[i];
    }

    return;

}

void mergeSort(int a[], int s, int e){
    //base case
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    //rec case
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    //we need to merge the above two sorted part of array
    merge(a, s, e);

    return;
}

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<cnt<<endl;

    return 0;
}
