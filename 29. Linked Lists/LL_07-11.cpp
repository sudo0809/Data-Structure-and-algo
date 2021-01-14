#include<iostream>
using namespace std;
//Operator overloading <<, >>
// Reversing a LL and Recursively reversing
// Mid point Runner Techgnoque
// Kth Node from end

class node{
public:
    int data;
    node*next;

    node(int d){
        data = d;
        next = NULL;
    }
};
void print(node*&head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
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

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}

istream& operator>>(istream &is, node*&head){
    head = take_input();
    return is;
}

void reverse(node*&head){
    node* prev = NULL;
    node* current = head;
    node* forward;
    while(current !=NULL){
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
}

node* recReverse(node*head){
    //smallest ll
    if(head->next==NULL or head==NULL){
        return head;
    }
    //rec case
    node* shead = recReverse(head->next);

    // node*temp = shead;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    node* temp = head->next;

    head->next=NULL;
    temp->next=head;
    return shead;
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
    // node*head = take_input();
    // node*head2 = take_input();
    node*head;
    cin>>head;
    cout<<head; //printing the entire LL
    // head = recReverse(head);
    // cout<<head;

    // node*mid = midpoint(head);
    // cout<<mid->data<<endl;

    node*Kth = KthNodeFromEnd(head, 3);
    cout<<Kth->data<<endl;
}
