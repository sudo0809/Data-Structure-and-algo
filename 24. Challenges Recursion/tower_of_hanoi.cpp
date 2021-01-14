#include<iostream>
using namespace std;

void moveDisk(int n, char start, char destination, char helper){
    if(n==0){
        return;
    }

    //rec case
    //so here n-1 disks are put to C using helper as B
    moveDisk(n-1, start, helper, destination);
    cout<<"Moving ring "<<n<<" from "<<start<<" to "<<destination<<endl;
    moveDisk(n-1, helper, destination, start);
}

int main(){
    int disks;
    cin>>disks;

    moveDisk(disks, 'A', 'B', 'C');
}
