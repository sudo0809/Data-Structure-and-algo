#include<iostream>
using namespace std;

void replacePi(char a[], int i){
    //base case
    if(a[i] == '\0' or a[i+1] == '\0'){
        return;
    }
    //recursive case
    //look for pi for current location
    if(a[i]=='p' and a[i+1]=='i'){
        //shifting + replacement with 3.14
        int j = i+2;

        //take j to the end of the array
        while(a[j] != '\0'){
            j++;
        }

        //shifting (right to left)
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }
        //replacement
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        //recursive call for the next part of the char array
        replacePi(a, i+4);
    }
    else{
        //go to the next position
        replacePi(a, i+1);
    }
    return ;
}

int main() {

    char a[1000];
    cin>>a;

    replacePi(a, 0);
    cout<<a<<endl;

    return 0;

}
