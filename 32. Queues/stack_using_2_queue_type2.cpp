#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// time complexity of push is O(N)
// and pop is O(1)

template<typename T>
class Stack{
    queue<T> q1, q2;

public:
    void push(T data){
        q2.push(data);

        while(!q1.empty()){
            T element = q1.front();
            q1.pop();
            q2.push(element);
        }
        swap(q1, q2);
    }
    void pop(){
        q1.pop();
    }
    T top(){
        return q1.front();
    }
    int size(){
        return q1.size() + q2.size();
    }
    bool empty(){
        return size()==0;
    }
};

int main(){
    Stack<int> s;

    for(int i=1;i<=5; i++){
        // cout<<i<<" ";
        s.push(i);
    }
    cout<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
