// Algorithm of subtraction of two linked list

/*

Code contains the following functions:
1. Length: To calculate the size of ll
2. Reverse: To reverse the ll
3. Parent function

Procedure:
1. Run a while loop to remove the trailing zeroes(if any) from both ll.
2. Calculate the length of both ll
3. If n2>n1: swap(l1,l2) to make sure the first ll is bigger number
4. If n1==n2: run a loop to find which number is bigger. If n2->data is bigger at some point, swap(l1,l2)to make sure the first ll is bigger number
5. Reverse the ll.
6. Subtract the linked list's.
7. Remove any trailing zeroes if any.

*/

int length(Node* n)
{
    int ret = 0;
    while(n)
    {
        ret++;
        n = n->next;
    }
    return ret;
}

Node* rev(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* nextnode = NULL;
    while(curr){
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

Node* subtract(Node* l1, Node* l2) {
    while(l1 && l1->data == 0)
        l1 = li->next;
    while(l2 && l2->data == 0)
        l2 = li->next;
    
    int n1 = length(l1);
    int n2 = length(l2);

    if(n2>n1)
        swap(l1,l2);
    if(n1==n2){
        Node *t1 = l1, *t2 = l2;
        while(t1->data == t2->data){
            t1 = t1->next;
            t2 = t2->next;

            if(!t1) return new Node(0);
        }
        if(t2->data > t1->data)
            swap(l1,l2);
    }

    l1 = rev(l1);
    l2 = rev(l2);

    Node *t1 = l1, *t2 = l2;
    Node* res = NULL;
    while(t1){
        int small = 0;
        if(t2)
            small = t2->data;
        
        if(t1->data < small){
            t1->next->data = t1->next->data - 1;
            t1->data = t1->data + 10;
        }
        Node* n = new Node(t1->data - small);
        n->next = res;
        res = n;

        t1 = t1->next;
        if(t2)t2->next;
    }
    while(res && res->next == 0)
        res = res->next;
    
    return res;
}