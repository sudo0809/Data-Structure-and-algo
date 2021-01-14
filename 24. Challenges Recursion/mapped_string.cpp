#include<iostream>
#include<cstring>
using namespace std;

int output[27]={'.','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void subAlphaString(char a[], char*out, int i, int j){

    //base case
    if(a[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return ;
    }

    //rec case
    int firstDigit = a[i] - '0';
    out[j] = output[firstDigit];
    subAlphaString(a, out, i+1, j+1);

    //taking two digits only if less than 27
    if(a[i+1] != '\0'){
        int secondDigit = a[i+1] - '0';
        int secondNum = 10*firstDigit + secondDigit;

        if(secondDigit<27){
            out[j] = output[secondNum];
            subAlphaString(a, out, i+2, j+1);
        }
    }

    return;
}

int main(){
    char a[100];
    cin>>a;

    char out[100];
    subAlphaString(a, out, 0, 0);

    return 0;
}
