#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Queue{
    stack<int> s1,s2;

public:
    void push(int data){
        s1.push(data);
    }
    void pop(){
        if(s1.empty()){
            return;
        }
        while(s1.size()>1){
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }
        s1.pop();
        while(s2.size()!=0){
            int element = s2.top();
            s2.pop();
            s1.push(element);
        }
    }
    int front(){
        while(s1.size()>1){
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }
        int front_element = s1.top();
        while(s2.size()!=0){
            int element = s2.top();
            s2.pop();
            s1.push(element);
        }
        return front_element;
    }
    int size(){
        return s1.size() + s2.size();
    }
    bool empty(){
        return size()==0;
    }

};

int main(){
    Queue q;

    for(int i=1; i<=5;i++){
        cout<<i<<" <- ";
        q.push(i);
    }
    cout<<endl;

    while(!q.empty()){
        cout<<q.front()<<" <- ";
        q.pop();
    }
}
