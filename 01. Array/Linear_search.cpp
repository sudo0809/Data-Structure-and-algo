
#include<iostream>
using namespace std;
 int main()
 {
    int n, key;
    cin>> n;
    int a[1000];
    for (int i=0; i<n; i++)
    {
        cin>> a[i];
    }

    cout<< "Enter the Element you want to search : ";
    cin>> key;
    // Linear search Algorithm
    int i;
    for(i=0; i<n; i++)
        {
        if (key == a[i])
        {
            cout<<"The index of the key "<<key<<" is : "<< i <<endl;
            break ;
        }
    }
    if(i == n){
        cout<<key<<" is not present "<< endl;
    }
 }
