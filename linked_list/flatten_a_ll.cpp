class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL)
            return NULL;

        Node* curr = head;

        while(curr != NULL){

            // if child exists
            if(curr->child != NULL){

                Node* childHead = flatten(curr->child); // flatten child
                Node* nextNode = curr->next;             // save original next

                // connect curr -> child
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // go to tail of child list
                Node* tail = childHead;
                while(tail->next != NULL){
                    tail = tail->next;
                }

                // reconnect tail -> nextNode
                tail->next = nextNode;
                if(nextNode != NULL)
                    nextNode->prev = tail;
            }

            // IMPORTANT: move forward
            curr = curr->next;
        }

        return head;
    }
};
