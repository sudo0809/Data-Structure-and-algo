#include<iostream>
using namespace std;
void Insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int e = arr[i];
        //Place the current element in the correct place in sorted part
        int j = i-1;
        while (j>=0 and arr[j]>e)
        {
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = e;
    }
}

int main() {
    int n;
    cin>> n;

    int arr[5000];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    Insertion_sort(arr, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<",";
    }


}
