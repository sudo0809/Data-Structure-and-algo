#include<iostream>
using namespace std;

int partition(int *a, int s, int e){

    int i = s-1;
    int pivot = a[e];
    for(int j=s; j<e; j++){
        if(a[j] <= pivot){
            i = i + 1;
            swap(a[i], a[j]);
        }
    }

    //putting pivot at the middle as a partition
    i = i+1;
    swap(a[i], a[e]);
    return i;

}

void Quicksort(int *a, int s, int e){

    //base case
    if(s>=e){
        return;
    }
    //recursive case
    int p = partition(a, s, e); //last element is the pivot element at index e
    Quicksort(a, s, p-1); // sorting left part
    Quicksort(a, p+1, e); // sorting right part

    return;
}

//Quicksort
int main(){
    int arr[] = {2,7,8,6,1,5,4};
    int n = sizeof(arr) / sizeof(int);

    Quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
