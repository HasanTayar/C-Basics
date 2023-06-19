#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* addNode(Node* head, int data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(head == NULL)
        return new_node;
    
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
        
    temp->next = new_node;
    return head;
}


void removeInstances(Node** head, int num) {
    Node* current = *head;
    Node* prev = NULL;
    
    while(current != NULL){
        if(current->data == num){
            if(prev == NULL)
                *head = current->next;
            else
                prev->next = current->next;
            
            free(current);
            current = (prev == NULL) ? *head : prev->next;
        }else{
            prev = current;
            current = current->next;
        }
    }
}

void insertAfter(Node** head, int num, int insertNum) {
    Node* current = *head;
    Node* new_node;
    
    while(current != NULL){
        if(current->data == num){
            new_node = (Node*) malloc(sizeof(Node));
            new_node->data = insertNum;
            new_node->next = current->next;
            current->next = new_node;
            current = new_node->next;
        }else
            current = current->next;
    }
}

int isSorted(Node* head) {
    while(head && head->next){
        if(head->data > head->next->data)
            return 0;
        head = head->next;
    }
    return 1;
}

Node* mergeSortedLists(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    
    while(head1 && head2){
        if(head1->data < head2->data){
            tail->next = head1;
            head1 = head1->next;
        }else{
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (head1) ? head1 : head2;
    return dummy.next;
}

Node* aboveAverage(Node* head) {
    Node* current = head;
    int sum = 0, count = 0;
    
    while(current){
        sum += current->data;
        count++;
        current = current->next;
    }
    
    int avg = sum / count;
    Node* dummy = (Node*) malloc(sizeof(Node));
    Node* tail = dummy;
    current = head;
    
    while(current){
        if(current->data > avg){
            tail->next = current;
            tail = current;
        }
        current = current->next;
    }
    
    tail->next = NULL;
    Node* new_head = dummy->next;
    free(dummy);
    return new_head;
}
void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    // Adding nodes to list 1
    head1 = addNode(head1, 1);
    head1 = addNode(head1, 2);
    head1 = addNode(head1, 3);
    head1 = addNode(head1, 2);
    head1 = addNode(head1, 5);
    
    // Adding nodes to list 2
    head2 = addNode(head2, 0);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 7);
    
    // Remove instances of the number 2 in list 1
    removeInstances(&head1, 2);
    
    // Insert a new node after every occurrence of the number 1 in list 1
    insertAfter(&head1, 1, 0);

    // Checking if list 1 is sorted
    if (isSorted(head1)) {
        printf("List 1 is sorted.\n");
    } else {
        printf("List 1 is not sorted.\n");
    }

    // Merging list 1 and list 2
    Node* merged_head = mergeSortedLists(head1, head2);
    
    // Print merged list
    Node* temp = merged_head;
    printf("Merged list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Get list of elements that are above average
    Node* above_avg = aboveAverage(merged_head);
    
    // Print list of elements above average
    temp = above_avg;
    printf("Nodes with values above average: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    //Free all the memo of head1 and head2
    freeList(head1);
    freeList(head2);

    return 0;
}

