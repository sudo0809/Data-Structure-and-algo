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

void sortedInsert(node*&head, node*new_node){
    node*temp;
    if(head==NULL or head->data > new_node->data){
        new_node->next = head;
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next!=NULL and temp->next->data < new_node->data){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void insertion_sort(node*&head){

    node*sorted = NULL;
    node*curr = head;
    while(curr!=NULL){
        node*next = curr->next;
        sortedInsert(sorted, curr);
        curr = next;
    }
    head = sorted;
}

int main(){
    int n;
    cin>>n;
    node*head = take_input(n);
    insertion_sort(head);
    print(head);
}
