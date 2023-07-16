void solve(Node* &head, Node* prev, Node* curr){
        if(curr == NULL){
            head = prev;
            return;
        }
        Node* forward = curr->next;
        solve(head, curr, forward);
        curr->next = prev;
    }
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* prev = NULL;
        Node* curr = head;
        
        solve(head, prev, curr);
        return head;
        // while(curr != NULL){
        //     Node* forward;
        //     forward = curr->next;
        //     curr->next=prev;
        //     prev = curr;
        //     curr=forward;
        // }
        // return prev;
    }
