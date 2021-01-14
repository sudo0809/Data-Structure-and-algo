#include<iostream>
using namespace std;

int tiling(int f){
    //base case
    //tiles are of size (1x4) and (4x1)
    //so if the wall length is less than 4 only (4x1) can be used
    if(f<=3){
        return 1;
    }

    //rec case
    int x = tiling(f-4);
    int y = tiling(f-1);

    return x+y ;
}

int main() {
    // f is the length of he wall horizontally
    //vertically the length of the wall is 4 (fixed)
    int f;
    cin>>f;
    //dimension of wall is 4xf

    cout<<tiling(f)<<endl;

    return 0;
}
