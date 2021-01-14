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
    while(tail ->next !=NULL){
        tail = tail->next;
    }
    tail ->next = new node(data);
    // cout<<"Head "<<head->data<<endl;
    return;
}

node* take_input(int n){
    int d;
    // cin>>d;
    node* head = NULL;
    while(n--){
        cin>>d;
        insertAtTail(head, d);
    }
    return head;
}


void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}

node* reverseK(node*&head, int k){

    node*curr = head;
    node*next = NULL;
    node*prev = NULL;
    int count=1;
    while(count<=k && curr!=NULL){
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr!=NULL){
        head->next = reverseK(curr, k);
    }

    return prev;
}

int main(){
    int n, k;
    cin>>n>>k;

    node*head = take_input(n);
    // cout<<head;
    head = reverseK(head, k);
    cout<<head;

}
