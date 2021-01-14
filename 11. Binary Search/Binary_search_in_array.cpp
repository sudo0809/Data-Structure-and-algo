#include<iostream>
using namespace std;

int  binary_search(int a[],  int n, int key){
    int s = 0;
    int e = n-1;
    // int m = (s+e)/2
    while(s<=e){
        int m = (s+e)/2;

        if(key == a[m]){
            return m;
        }
        else if(key< a[m]){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }

    return -1;

}


int main() {

    int n, key;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the key : ";
    cin>>key;

    int idx = binary_search(arr, n, key);
    cout<<idx;
}
