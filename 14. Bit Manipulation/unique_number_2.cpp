#include<iostream>
using namespace std;

//Given in an array, there are 2 unique number and all others are
//repeated twice. Find the numbers.

int main() {

    int n;
    cin>>n;

    int no[n];
    int xor_total = 0;

    for(int i=0; i<n; i++){
        cin>>no[i];
        xor_total = no[i]^xor_total;
    }
    //xor_total = a^b
    int temp = xor_total;
    int pos = 0;
    while((temp&1) != 1){
        pos++;
        temp = temp>>1;
    }
    //the first bit is at position 'pos'
    int mask = (1<<pos);

    //find those no. which contain set bit at position pos
    int x = 0;
    int y = 0;

    for(int i=0; i<n; i++){
        if((no[i]&mask) > 0){
            x = x^no[i];
        }
    }
    y = xor_total^x;

    cout<<min(x,y)<<" "<<max(x,y);




    return 0;
}
