#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    //recc case
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void recReverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    //pop out the top element and insert it at the botto, of 'reversed smaller stack'
    int x = s.top();
    s.pop();
    recReverseStack(s);
    insertAtBottom(s, x);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    recReverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
