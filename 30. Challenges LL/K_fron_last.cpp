#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*&head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

node* take_input(){
    int d;
    cin>>d;
    node*head = NULL;
    while(d!=-1){
        insertAtTail(head, d);
        cin>>d;
    }
    return head;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

node* KthNodeFromEnd(node*head, int k){
    //corner cases
    if(head==NULL){
        return head;
    }

    node*forward = head;
    while(k){
        forward = forward->next;
        k -=1;
    }
    node*back = head;

    while(forward!=NULL){
        forward = forward->next;
        back = back->next;
    }
    return back;
}

int main(){
    node*head = take_input();
    int k;
    cin>>k;
    node*element = KthNodeFromEnd(head, k);
    cout<<element->data;
}
