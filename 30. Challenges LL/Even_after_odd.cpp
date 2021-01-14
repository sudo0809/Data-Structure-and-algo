#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d){
        data=d;
        next=NULL;
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
    cout<<endl;
    return;
}

node* evenAfterOdd(node*&head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node*even_head = NULL;
    node*odd_head = NULL;

    node*temp_head = head;
    // node*odd_ptr=odd_head;
    // node*even_ptr=even_head;

    while(temp_head!=NULL){
        if(temp_head->data%2 != 0){
            insertAtTail(odd_head,temp_head->data);
        }
        else{
            insertAtTail(even_head,temp_head->data);
        }
        temp_head = temp_head->next;
    }

    if(odd_head==NULL)
        odd_head=even_head;
    else{
        node*temp = odd_head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = even_head;
    }
    return odd_head;
}

int main(){
    int n;
    cin>>n;
    node*head = take_input(n);
    head = evenAfterOdd(head);
    print(head);
}
