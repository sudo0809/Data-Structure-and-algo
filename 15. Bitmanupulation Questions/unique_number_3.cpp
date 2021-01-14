#include<iostream>
#include<cmath>
using namespace std;

//Given an array, all the numbers present thrice except one number
//Find that unique number

int main() {
    int n;
    cin>>n;

    int a[n];
    int max_int = 0;

    for(int i=0; i<n; i++){
        cin>>a[i];
        max_int = max(a[i], max_int);
    }
    //Bitwise summing
    int sum[n] = {0}; // this keeps track og the sum of all bits at position 'pos'
    int pos = 0;
    //while loop runs till max element value
    while((max_int) > 0){
        for(int i=0; i<n; i++){
            // int temp = a[i];
            if((a[i]>>pos)&1 > 0){
                sum[pos] += (a[i]>>pos)&1 ;
            }
        }
        pos++;
        max_int = max_int >> 1;
    }

    int number = 0;
    int r = 1;
    for(int i=0; i<pos; i++){
        number += (sum[i]%3) * pow(2, i);
    }
    cout<<number<<endl;
}
