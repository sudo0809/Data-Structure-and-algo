#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {20, 30, 40, 40, 40, 290, 1000};
    int n = sizeof(arr)/sizeof(int);
    //Search in a sorted array
    int key;
    cin>>key;

    bool present = binary_search(arr, arr+n, key);
    if(present){
        cout<<"present";
    }
    else{
        cout<<"absent!";
    }

    //Get the index of the element
    //lower_bound(s,e,key) and upper_bound(s,e,key)
    auto lb = lower_bound(arr, arr+n, key);
    cout<<endl<<"lower bound of "<<key<<" is "<<lb-arr<<endl;

    //upper_bound
    auto ub = upper_bound(arr, arr+n, key);
    cout<<"upper bound is "<<ub-arr<<endl;

    //frequency of key
    cout<<"occurance Frequency of "<<key<<" is "<<ub - lb<<endl;

    return 0;
}
