#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n, key;
    cin>> n;

    int a[1000];

    for(int i=0; i<n; i++)
    {
        cin>> a[i];
    }
    //Algorithm to find the largest and the smallest
    int smallest = INT_MAX;
    int largest = INT_MIN;

    // Method 1
    /*for(int i=0; i<n; i++){
        if(a[i] < smallest){
            smallest = a[i];
        }
        if(a[i]>largest){
            largest = a[i];
        }
    }*/

    // Method 2
    for(int i = 0; i<n; i++){
        largest = max(largest,a[i]);
        smallest = min(smallest,a[i]);
    }
    cout<<"smallest "<<smallest<<endl;
    cout<<"Largest "<<largest;
}
