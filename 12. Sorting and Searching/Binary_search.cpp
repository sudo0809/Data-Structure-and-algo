#include<iostream>
using namespace std;

int binarySearch(long long int a[], long long int n, long long int key){

    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == key)
            return mid;
        else if(a[mid] < key){
            s = mid+1;
        }
        else{
            e = mid -1;
        }
    }

    return -1;
}


int main(){

    long long int n;
    cin>>n;
    long long int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long long int key;
    cin>>key;

    int idx = binarySearch(arr, n, key);
    cout<<idx<<endl;


    return 0;
}
