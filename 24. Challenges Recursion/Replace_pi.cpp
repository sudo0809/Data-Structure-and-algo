#include<iostream>
using namespace std;

void replacePi(char a[], int i){
    //base case
    if(a[i]=='\0' or a[i+1]=='\0'){
        return;
    }
    //recursive case
    if(a[i]=='p' and a[i+1]=='i'){

        int j = i+2;

        //take pointer j to end
        while(a[j] != '\0'){
            j++;
        }

        //shifting elements to right
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }

        //replacing Pi
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        //rec case
        replacePi(a, i+4);
    }
    else{
        replacePi(a, i+1);
    }

    return;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        char *arr = new char[1000];
        cin>>arr;

        replacePi(arr, 0);

        cout<<arr<<endl;

        delete arr;
    }


    return 0;
}
