int length(Node *head){
    int count=0;
    while(head!=NULL){
        head = head->next;
        count++;
    }
    return count;
}

Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    // Node* l1_ptr = l1;
    // Node* l2_ptr = l2;
    // while(l1_ptr!=l2_ptr){
    //     l1_ptr = l1_ptr->next;
    //     l2_ptr = l2_ptr->next;
    //     if(l1_ptr==NULL){
    //         l1_ptr = l2;
    //     }
    //     if(l2_ptr==NULL){
    //         l2_ptr = l1;
    //     }
    // }
    // return l1_ptr;

    Node* l1_front = l1;
    Node* l2_front = l2;
    while(l1->next!=NULL or l2->next!=NULL){
        l1_front = l1_front->next;
        l1->next = NULL;
        l1 = l1_front;

        l2_front = l2_front->next;
        l2->next = NULL;
        l2 = l2_front;
    }
    if(l1->next==NULL){
        return l1;
    }
    if(l2->next==NULL){
        return l2;
    }
}
