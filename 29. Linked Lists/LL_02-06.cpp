#include<iostream>
using namespace std;

//Insetion , Deletion, Searching, take input

class node{
public:
    int data;
    node*next;

    //constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

//Linked Class (object oriented)
/*
class LinkedList{
    node*head;
    node*tail;

public:
    LinkedList(){
    }
    void insert(int d){

    }
    ...

};
*/

//Functions (procedural Programming)
void build(){

}
//using '&' here means you are passing value by reference
//only with the changes inside then funtion can be seen even outside the function
int length(node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head = head -> next;
    }
    return cnt;
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

void insertAtMiddle(node*&head, int data, int pos){
    //corner case
    if(head==NULL or pos==0){
        insertAtHead(head, data);
    }
    else if(pos>length(head)){
        insertAtTail(head, data);
    }
    else{
        //take p-1 jumps
        int jump = 1;
        node*temp = head;
        while(jump <= pos-1){
            temp = temp -> next;
            jump++;
        }
        //create a new node
        node *n = new node(data);
        n -> next = temp -> next;
        temp -> next = n;
    }

}

void print(node*head){
    while (head!=NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head -> next;
    delete head;
    head = temp;
}
void deleteTail(node*&head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        return;
    }
    node*temp = head;
    node*second_last = head;
    while(second_last->next->next != NULL){
        second_last = second_last->next;
    }
    head = second_last->next;
    delete head;
    second_last ->next = NULL;
    head = temp;
}

void deleteMiddle(node*&head, int pos){
    if(head==NULL){
        return;
    }
    else if(pos==0){
        head =  head->next;
        delete head;
        return;
    }
    else if(pos>length(head)){
        cout<<"Out of bound"<<endl;
        return;
    }
    else{
        int jump=1;
        node*temp = head;
        while(jump < pos-1){
            temp = temp -> next;
            jump++;
        }
        node*deleting_node = temp->next;
        temp ->next = deleting_node->next;
        delete deleting_node;
    }
}

bool search(node*head, int key){
    node*temp = head;
    while(temp!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
        temp = head;
    }
    return false;
}
//recursively
bool recSearch(node*head, int key){
    if(head==NULL){
        return false;
    }
    if(head -> data == key){
        return true;
    }
    else{
        return recSearch(head->next, key);
    }
}
/*
void take_input(node*head){
    //takking head and then adding node point to it
}*/
node* take_input(){
    //making a node imput and the giving this to main
    int d;
    cin>>d;
    node*head=NULL;
    while(d!=-1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

int main(){
    node*head = take_input();
    print(head);
    /*
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 7);
    insertAtHead(head, 1);
    print(head);

    insertAtMiddle(head, 4,3);
    insertAtTail(head, 15);

    print(head);
    // deleteTail(head);
    deleteMiddle(head, 0);
    print(head);

    int key = 1;
    if(recSearch(head, key)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
*/
}
