#include <bits/stdc++.h>

class node {                                // Node Definition
    public:
        int data;
        node* next;

        node(int val) {                     // Default Constructor
            data = val;
            next = NULL;  
        }
};

void insertAtHead(node* &head, int val) {           // Inserts a node at the beginning;
    node* n = new node(val);
    n->next = head;
    head = n; 
}

void insertAtTail(node* &head, int val) {           // Inserts a node at the end;
    node* n = new node(val);
        if (head == NULL) {
            head = n;
            return;
        }
    node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
}

void display(node* head) {                      // To display the linked list
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << '\n';
}

node* reverse_k_nodes(node* &head, int k) {              // To reverse K nodes;
    node* previous = NULL;
    node* current = head;
    node* next;

    int count = 0;
        while (current != NULL and count < k) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            count++;
        }
        if (next != NULL) {
            head->next = reverse_k_nodes(next, k);
        }
        return previous;
}

bool search(node* head, int key) {          // Search function
    node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
                return false;
}

bool DetectCycle(node* &head) {             // Detects if there is any cycle present in a list (Hare and Tortoise algorithm)
    node* HARE = head;
    node* TORTOISE = head;

        while (HARE != NULL and HARE->next != NULL) {
            TORTOISE = TORTOISE->next;
            HARE = HARE->next->next;

            if (HARE == TORTOISE) {
                return true;                // 1 if cycle is found; 0 if not found
            }
        }
        return false;
}

   
void MakeCycle(node* &head, int pos) {          // Makes a cycle in a list (It will go on forever)
    node* temp = head;
    node* StartNode;

    int count = 1;
        while (temp->next != NULL) {
            if (count == pos) {
                StartNode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = StartNode;
}

void RemoveCycle(node* &head) {             // Removes a formed cycle 
    node* HARE = head;
    node* TORTOISE = head;
        do {
            TORTOISE = TORTOISE->next;
            HARE = HARE->next->next;
        } while (TORTOISE != HARE);

        HARE = head;
            while (TORTOISE->next != HARE->next) {
                TORTOISE = TORTOISE->next;
                HARE = HARE->next;
            }

            TORTOISE->next = NULL;
}

int length(node *head) {                            // Calculates the length of a linked list
    int l = 0;
    node* temp = head;
        while (temp != NULL) {
            l++;
            temp = temp->next;
        }
        return l;
}

node* K_append(node* &head, int k) {                // Appends given k nodes at the head
    node* NewHead;
    node* NewTail;
    node* tail = head;

    int l = length(head);
    k = k % l;    
    int count = 1;
        while (tail->next != NULL) {
            if (count == l - k) {
                NewTail = tail;  
            }
            if (count = l - k + 1) {
                NewHead = tail;
            }
            tail = tail->next;
            count++;
        }

        return NewHead;
}

void circular_insertAtHead(node* &head, int val) {              // Inserts a element at the head (beginning)
    node* n = new node(val);
    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }
    node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        head = n;

}

void circular_insertAtTail(node* &head, int val) {              // Inserts a element at the tail (ending)
    if (head == NULL) {
        circular_insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
}

void circular_delete_at_head(node* &head) {                     // Deletes a node at beginning
    node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        node* to_delete = head;
        temp ->next = head->next;
        head = head->next;

        delete to_delete;
}

void circular_delete(node* &head, int pos) {
    if (pos == 1) {
        circular_delete_at_head(head);
    }

    node* temp = head;
    int count = 1;
        while (count != pos - 1) {
            temp = temp->next;
            count++;
        }
        node* ToDelete = temp->next;
        temp->next = temp->next->next;

        delete ToDelete;
}

void do_intersect(node* &head1, node* head2, int pos) {             // Creates a intersection between two linked list
    node* temp1 = head1;
        pos--;
        while (pos--) {
            temp1 = temp1->next;
        }
        node* temp2 = head2;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        
        temp2->next = temp1;
}

int is_intersecting(node* &head1, node* &head2) {                   // Checks if linked list(s) are intersecting
    int L1 = length(head1);
    int L2 = length(head2);
    int d = 0;

    node* ptr1;
    node* ptr2;
        if (L1 > L2) {
            d = L1 - L2;
            ptr1 = head1;
            ptr2 = head2;
        }
        else {
            d = L2 - L1;
            ptr1 = head2;
            ptr2 = head1;
        }
            while (d) {
                ptr1 = ptr1->next;
                    if (ptr1 == NULL) {
                        return -1;
                    }
                d--;
            }
            while (ptr1 != NULL and ptr2 != NULL) {
                if (ptr1 == ptr2) {
                    return ptr1->data;
                }
                
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            return -1;
}

node* merge(node* &head1, node* &head2) {           // Merges two singly linked list
    node* p1 = head1;
    node* p2 = head2;
    node* dummy = new node(-1);
    node* p3 = dummy;

        while (p1 != NULL and p2 != NULL) {
            if (p1->data < p2->data) {
                p3->next = p1;
                p1 = p1->next;
            }
            else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
            while (p1 != NULL) {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;

            }
            while (p2 != NULL) {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;

            }

            return dummy->next;
}

node* merge_Recursive(node* &head1, node* head2) {          // Merges two singly linked list (Recursive Approach)
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    node* result;
        if (head1->data < head2->data) {
            result = head1;
            result->next = merge_Recursive(head1->next, head2);
        }
        else {
            result = head2;
            result->next = merge_Recursive(head1, head2->next);
        }
    return result;
}

void deleteAtHead(node* &head) {            // Deletes the node at the beginning 
    node* to_delete = head;
    head = head->next;

    delete to_delete;
}

void deleteNode(node* &head, int val) {         // Deletes any given node

    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
        while(temp->next->data != val) {
            temp = temp->next;
        }
        node* to_delete = temp->next;
        temp->next = temp->next->next;

        delete to_delete;
}

node* reverse(node* &head) {            // Iterative Approach of reversing a list
    node* previous = NULL;
    node* current = head;
    node* next;

        while (current != NULL) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

    return previous;
}

node* reverseRecursive(node* &head) {                   // Recursive Approach of reversing a list

    if (head == NULL or head->next == NULL) {
        return head;
    }

    node* ReverseHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return ReverseHead;
}

void Put_even_after_odd(node* &head) {
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
        while (odd->next != NULL and even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next; 
            even = even->next; 
        }
        odd->next = evenStart;
            if (odd->next != NULL) {
                even->next = NULL;
            }
}

signed main(void) {                                     // Driver Code (LOL)

}
