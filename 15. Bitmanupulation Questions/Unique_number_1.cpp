#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int a[n];
    int no = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        no = no^a[i];
    }
    cout<<no<<endl;

    return 0;
}
