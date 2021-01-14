#include<iostream>
using namespace std;
//merging two sorted Linked List
//merge sort

class node{
public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream& os, node*head){
    print(head);
    return os;
}

void insertAtHead(node*&head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*n = new node(d);
    n->next = head;
    head = n;
    return;
}

node* take_input(){
    int d;
    cin>>d;
    node* head = NULL;
    while(d!=-1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream &is, node*&head){
    head = take_input();
    return is;
}
node* midpoint(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node*slow = head;
    node*fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node*a, node*b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    // temp head pointer
    node*c;

    if(a->data < b->data){
        c = a;
        c->next = merge(a->next, b);
    }
    else{
        c = b;
        c -> next = merge(a, b->next);
    }
    return c;
}

node* mergeSort(node*head){
    //base case
    if(head==NULL or head->next==NULL){
        return head;
    }
    //rec case
    node* mid = midpoint(head);
    node*a = head;
    node*b = mid -> next;

    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    node*c = merge(a, b);

    return c;
}

int main(){
    // node*head;
    // cin>>head;
    // cout<<head;
    /*
    node*a;
    node*b;
    cin>>a>>b;

    node*sortedLL = merge(a, b);
    cout<<sortedLL<<endl;
    */
    node*head;
    cin>>head;
    cout<<head;
    head = mergeSort(head);
    cout<<head<<endl;
}
