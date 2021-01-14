#include<iostream>
#include<algorithm>
using namespace std;

//Define a comparator Function
bool compare(int a, int b)
{
    return a > b;
}
int main() {
    int n;
    cin>> n;

    int arr[5000];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //Sort an array using sort() function
    sort(arr, arr + n, compare);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<",";
    }


}
