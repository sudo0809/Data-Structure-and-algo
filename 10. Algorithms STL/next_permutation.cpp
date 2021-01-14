#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(int);

    rotate(arr, arr+2, arr+n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Apply the same on a vector
    vector<int> v{10, 20, 30, 40, 50};
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    rotate(v.begin(), v.begin()+2, v.end());

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Next_permutation
    vector<int> v1{1,2,3};
    next_permutation(v1.begin(), v1.end());

    for(int x:v1){
        cout<<x<<" ";
    }
    cout<<endl;
    next_permutation(v1.begin(), v1.end());

    for(int x:v1){
        cout<<x<<" ";
    }


    return 0;
}
