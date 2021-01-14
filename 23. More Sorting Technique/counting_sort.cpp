#include<iostream>
using namespace std;

void countSort(int *a, int n){

    //find the largest, assuming element is greater than 0
    int largest = -1;
    for(int i=0; i<n; i++){
        largest = max(largest, a[i]);
    }

    int *freq = new int[largest+1]{0};

    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }

    //put the elements back into the array a
    int j=0; //pointer for the array a
    for(int i=0; i<=largest; i++){

        while(freq[i]>0){
            a[j] = i;
            j++;
            freq[i]--;
        }
    }
    return;
}

int main() {

    int arr[] = {88, 97, 20, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(int);

    countSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
