#include<iostream>
using namespace std;

// int main(){
//
//     char *p;
//
//     char sample[] = "codingblocks";
//
//     p = sample;
//     p+=6;
//     cout<<p;
//
//     return 0;
// }

int main() {
    int arr[]={0,1,2,3,4};

    int i, *ptr;
    for(ptr= arr, i=0; ptr+i <= arr+4; ptr++, i++)
        cout<<*(ptr+i);
    return 0;
}




1) C
2) C
3) B
4) B
5) D
6) B
7) C
8) B
