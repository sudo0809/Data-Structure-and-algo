#include<iostream>
using namespace std;

int last_occurance(int a[], int n, int key){
    int s = 0;
    int e = n-1;

    int ans = -1;
    while(s<=e){
        int m = (s+e)/2;

        if(key == a[m]){
            ans = m;
            s = m+1;
        }
        else if(key< a[m]){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }

    return ans;
}


int first_occurance(int a[], int n, int key){
    int s = 0;
    int e = n-1;

    int ans = -1;
    while(s<=e){
        int m = (s+e)/2;

        if(key == a[m]){
            ans = m;
            e = m-1;
        }
        else if(key< a[m]){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }

    return ans;
}


int main() {
    int n, key;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Enter the key : ";
    cin>>key;

    cout<<first_occurance(a, n, key)<<endl;
    cout<<last_occurance(a, n, key)<<endl;

    return 0;
}
