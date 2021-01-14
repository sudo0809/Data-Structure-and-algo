#include<iostream>
using namespace std;

int storeOcc(int *a, int i, int n, int key, int *out, int j){
    //base case
    if(i == n){
        return j;
    }
    if(a[i] == key){
        out[j] = i;
        // increment j to accomodate cutrrent occ
        return storeOcc(a, i+1, n, key, out, j+1);
    }
    return storeOcc(a, i+1, n, key, out, j);
}

void allOccur(int *a, int i, int n, int key){
    if(i==n){
        return ;
    }
    if(a[i]==key){
        cout<<i <<",";
    }
    allOccur(a, i+1, n, key);
}

int lastOcc(int *a, int n, int key){
    //base case
    if(n==0){
        return -1;
    }

    //rec case
    int i = lastOcc(a+1, n-1, key);
    if(i==-1){
        if(a[0]==key){
            return 0;
        }
        return -1;
    }
    return i+1;

}


int firstOcc(int *a, int n, int key){
    if (n==0) {
        return -1;
    }
    //rec case

    if(a[0]==key){
        return 0;
    }
    int i = firstOcc(a+1, n-1, key);
    if(i == -1){
        return -1;
    }
    return  i+1 ;

}

//Different way to write the same function
int LinearSearch(int *a, int i, int n, int key){

    //base case
    if(i==n){
        return -1;
    }
    //rec case
    if(a[i]==key){
        return i;
    }
    return LinearSearch(a, i+1, n, key);
}


int main() {

    int arr[] = {1,2,3,7,4,5,6,7,10};
    int key = 7;
    int n = sizeof(arr) / sizeof(int);

    cout<<firstOcc(arr, n, key)<<endl;
    cout<<LinearSearch(arr, 0, n, key)<<endl;
    cout<<lastOcc(arr, n, key)<<endl;
    allOccur(arr, 0, n, key);

    cout<<endl;
    int out[100];
    int count = storeOcc(arr, 0, n, key, out, 0);
    cout<<"Count "<<count<<endl;

    for(int i=0; i<count; i++){
        cout<<out[i]<<",";
    }


    return 0;
}
