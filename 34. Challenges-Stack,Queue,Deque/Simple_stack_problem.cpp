#include<iostream>
#include<stack>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a[2];
    stack<int> s;
    while(t--){
        cin>>a[0];
        if(a[0]==1){
            if(s.size()!=0){
                cout<<s.top()<<endl;
                s.pop();
            }
            else{
                cout<<"No Code"<<endl;
            }
        }
        else{
            cin>>a[1];
            s.push(a[1]);
        }
    }
    return 0;
}
