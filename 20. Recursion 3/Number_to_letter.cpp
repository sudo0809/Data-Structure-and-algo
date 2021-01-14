#include<iostream>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven","eight", "nine"};

void numToSpell(int n){
    //base case
    if(n==0){
        return;
    }
    //recursive case
    numToSpell(n/10);
    int digits = n % 10;
    cout<<words[digits] << " ";
}

int main(){

    int num;
    cin>>num;

    numToSpell(num);

    return 0;
}
