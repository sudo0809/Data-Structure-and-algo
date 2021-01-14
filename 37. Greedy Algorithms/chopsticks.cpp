#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, d;
    cin>>n>>d;
    int l[100];
    for(int i=0; i<n; i++){
        cin>>l[i];
    }

    sort(l, l+n);
    int pairs = 0;
    int ptr = 0;
    while(ptr<n){
        if(abs(l[ptr] - l[ptr+1])<=d){
            pairs++;
            ptr = ptr+2;
        }
        else{
            ptr++;
        }
    }
    cout<<pairs<<endl;



    return 0;
}
