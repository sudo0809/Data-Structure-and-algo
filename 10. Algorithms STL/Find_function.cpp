#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1, 2 ,44, 35, 288};
    int n = sizeof(arr)/sizeof(int);
    //search --> find

    int key;
    cin>>key;
    auto it = find(arr, arr+n, key);
    int index = it - arr;

    if(index==n){
        cout<<key<<" is not present"<<endl;
    }
    else{
        cout<<"Present at "<<index;
    }
}
