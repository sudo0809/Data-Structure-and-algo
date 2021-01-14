#include<iostream>
using namespace std;
int main()
{
    int a[1000];
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int cs=0;
    int ms=0;
    // Kadane's Method for finding max sum of sub-array
    for(int i=0;i<n;i++){
        cs = cs+a[i];
        cout<<cs<<endl;
        if(cs<0){
            cs = 0;
        }

        ms = max(cs, ms);
    }

    cout<<"Maximum Sum is "<<ms<<endl;


    return 0;
}
