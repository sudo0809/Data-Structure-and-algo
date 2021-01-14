#include<iostream>
using namespace std;

void merge(int *a, int s, int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];
    while(i<=mid and j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    while (j<=e){
        temp[k++] = a[j++];
    }

    //We need to copy all the element to the original array
    for(int i=s; i<=e; i++){
        a[i] = temp[i];
    }
    return;
}

void mergeSort(int a[], int s, int e){

    //base case
    if(s>=e){
        return;
    }

    //Rec case
    //Step 1: Divide
    int mid = (s+e)/2;

    //Recursively the array - s, mid and mid+1, e
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    //Finally Merge the array
    merge(a, s, e);
    return;
}


int main(){

    int a[] = {5,6,1,4,2,0};
    int n = sizeof(a) / sizeof(int);

    mergeSort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
