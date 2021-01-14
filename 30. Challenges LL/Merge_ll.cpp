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

node* merge(node*a, node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    node*c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n1;
        cin>>n1;
        node*head = take_input(n1);
        // print(head);
        int n2;
        cin>>n2;
        node*head2 = take_input(n2);
        // print(head2);

        head = merge(head, head2);
        print(head);
    }
}
