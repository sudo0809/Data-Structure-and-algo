#include<iostream>
using namespace std;

int main(){

    //Problem - UNique Number 2N + 1
    //Given a list of numbers where every number occure twice except one, find
    int n;
    cin>>n;

    int no;
    int ans = 0;
    //Bitwise XOR operator to solve
    // Helped not to use any storage

    for(int i=0; i<n; i++){
        cin>>no;
        ans = ans^no;
    }
    cout<<ans<<endl;

    return 0;
}
