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

node* take_input(int n){
    node*head = NULL;
    int d;
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
    cout<<endl;
    return;
}

node* appendK(node*&head,int n, int k){
    //corner cases
    if(head==NULL){
        return head;
    }
    if(k>n){
        k=k%n;
    }
    if(k==0 or k==n){
        return head;
    }

    node*forward = head;
    int start_list = n-k-1;
    while(start_list){
        forward = forward->next;
        start_list -=1;
    }
    node*new_head=forward->next;
    forward->next=NULL;
    node*ptr2 = new_head;

    while(ptr2->next!=NULL){
        ptr2 = ptr2->next;
    }
    ptr2->next=head;

    return new_head;
}

int main(){
    int n;
    cin>>n;
    node *head = take_input(n);
    int k;
    cin>>k;

    head = appendK(head,n, k);
    print(head);
}
