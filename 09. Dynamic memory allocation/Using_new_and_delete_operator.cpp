#include<iostream>
using namespace std;

int main() {

    //static allocation + deallocation
    int b[100]; // b[100] = {0}   ....to initialize all to zero
    cout<<sizeof(b)<<endl; // stored in symbol table
    //here b can't be overwritten, b is a part of Read Only Memory

    //Dynamic allocation
    int n;
    cin>>n;
    int *a = new int[n]; //new int[n]{0}   .... to initialize all to zero
    cout<<sizeof(a)<<endl;
    cout<<a<<endl; //variable a that is created inside the static memory -> overwritten
    // a = new char[30];

    for(int i=0; i<n; i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }

    //Freeup the namespace
    delete [] a;


    return 0;
}
