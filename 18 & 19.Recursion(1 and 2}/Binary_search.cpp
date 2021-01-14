#include<iostream>
using namespace std;

void b_s(int a[], int s, int e, int key){

    int mid = (s+e)/2;
    // cout<<a[mid]<< " "<<mid<<endl;
    if(a[mid]==key){
        cout<<mid<<endl;
        return;
    }
    else if(a[mid]<key){
        s = mid + 1;
        b_s(a+mid-s, s, e, key);
        return;
    }
    else{
        e = mid - 1;
        b_s(a+mid-s, s, e, key);
        return;
    }

}

int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    // int arr[6] = {1,2,3,4,10,20};
    // int key = 10;

    b_s(arr, 0, n-1, key);

    // cout<<(arr+4)[2]<<endl;
    return 0;

}
