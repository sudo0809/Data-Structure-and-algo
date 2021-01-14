#include<iostream>
#include<queue>
using namespace std;

int main(){

    int n;
    int a[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    queue<int> q;

    // int main_ptr=0;
    // int temp_ptr = 1;
    int temp = 1;
    for(int ptr=0; ptr<n; ptr++){
        // int temp = ptr+1;
        while(temp%n!=ptr and a[temp%n]<=a[ptr]){
            temp++;
        }
        if(temp%n == ptr){
            //pop out all
            while(!q.empty() and q.front()<=a[ptr]){
                q.pop();
            }
            if(q.empty()){
                cout<<-1<<" ";
            }
            else{
                cout<<q.front()<<" ";
            }
            temp = temp+2;
        }
        else{
            while(q.front()<=a[ptr] and !q.empty()){
                q.pop();
            }
            q.push(a[temp%n]);
            cout<<q.front()<<" ";
            temp++;
        }

    }


    return 0;
}
