#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int a;
        cin>>a;

        int step = 0;
        while(a>0){
            if(a&1){
                step++;
            }
            a = a>>1;
        }
        cout<<step<<endl;
    }
    return 0;
}
