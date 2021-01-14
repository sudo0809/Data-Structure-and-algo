#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*& head, int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(data);

    return;
}

node* take_input(int n){
    int d;
    node*head = NULL;
    while(n--){
        cin>>d;
        insertAtTail(head, d);
    }
    return head;
}

void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

void insertAtHead(node*&head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

bool checkPallindrome(node*head, int n){
    int mid = n/2;
    node*temp = head;
    node*pallin_head=NULL;
    while(mid--){
        insertAtHead(pallin_head, temp->data);
        temp = temp->next;
    }
    if(n%2!=0){
        temp=temp->next;
    }
    while(temp!=NULL){
        if(temp->data!=pallin_head->data){
            return false;
        }
        temp = temp->next;
        pallin_head = pallin_head->next;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    node*head = take_input(n);
    if(checkPallindrome(head, n)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

}
