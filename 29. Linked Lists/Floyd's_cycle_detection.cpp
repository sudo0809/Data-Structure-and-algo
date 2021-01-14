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

bool detectCycle(node*head){
    node*fast = head;
    node*slow = head;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}


node* breakCycle(node*head){
    node*fast = head;
    node*slow = head;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            slow = head;
            node*end_node;
            while(fast!=slow){
                end_node = fast;
                fast = fast->next;
                slow = slow->next;
            }
            end_node->next = NULL;
            return head;
        }
    }

    return head;
}

int main(){
    node*head;
    // cin>>head;
    head = take_input();
    cout<<head;

    node*loop_start = head->next;
    loop_start->next->next->next->next = loop_start;
    // cout<<head<<endl;
    if(detectCycle(head)){
        cout<<"Loop detected"<<endl;
        head = breakCycle(head);
        cout<<head<<endl;
    }
    else{
        cout<<"no loop detected"<<endl;
    }

}
