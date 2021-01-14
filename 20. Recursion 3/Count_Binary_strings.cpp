#include<iostream>
using namespace std;

int countBinaryString(int n){

    //base case
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }

    //rec case
    //string ends with 0
    int end_zero = countBinaryString(n-1);
    //string ends with 1 so n-1 th term should strictly be 0
    int end_one = countBinaryString(n-2);

    return end_zero + end_one;

}

int main(){
    int n;
    cin>>n;

    cout<<countBinaryString(n)<<endl;

    return 0;
}
