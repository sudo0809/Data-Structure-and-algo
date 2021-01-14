#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// time complexity of push is O(1)
// and pop is O(N)

template<typename T>
class Stack{
    queue<T> q1, q2;

public:
    void push(T x){
        q1.push(x);
    }
    void pop(){
        //remove last added element from q1
        //remove first n-1 element in the empty queue
        //interchange the name of q1 and q2
        if(q1.empty()){
            return;
        }
        while(q1.size()>1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }
        //removing the last element
        q1.pop();
        //swap the name of q1 and q2
        // queue<T> temp = q1;
        // q1 = q2;
        // q2 = temp;
        swap(q1, q2);


    }
    int top(){
        while(q1.size()>1){
            T element = q1.front();
            q2.push(element);
            q1.pop();
        }

        T element = q1.front();
        q1.pop();
        q2.push(element);
        swap(q1, q2);
        return element;
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
    for(int i=1; i<=5; i++){
        s.push(i);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}
