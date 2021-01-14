#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *a, int n){
    //base case
    if(n==0){
        return 0;
    }
    //recursive case
    //first print (123)
    int digit = a[n-1] - '0';
    int small_ans = stringToInt(a, n-1);

    return small_ans *10 + digit;
}


int main() {

    //Give a string convet it into int
    char a[] = "1234";
    int len = strlen(a);

    int x = stringToInt(a, len);
    cout<<x<<endl;
    cout<<x+1<<endl;


    return 0;
}
