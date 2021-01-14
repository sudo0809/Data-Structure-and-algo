#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>> n;

    int arr[1000];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Giving the start
    for(int i=0;i<n;i++){
        //Giving or Iterating the start for every start
        for(int j=i;j<n;j++){
            //Element of subarray between index i and j
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<",";
            }
            cout<<endl;
        }
    }

    return 0;
}
