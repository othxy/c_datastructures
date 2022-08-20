# include <stdio.h>
# include <stdlib.h>

typedef struct Node_int {
    int data;
    struct Node_int* next;
} Node_int;

void push_node__int(Node_int** head_ref, int data){
    Node_int* new_node = (Node_int*)malloc(sizeof(Node_int));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insert_node_at_pos__int(Node_int** head_ref, int data, int pos){
    if (pos < 2){
        push_node__int(head_ref, data);
    }

    Node_int* curr_node = *head_ref;
    Node_int* new_node = (Node_int*)malloc(sizeof(Node_int));
    new_node->data = data;
    
    int counter = 1;
    while (curr_node != NULL){
        
        if (counter == (pos - 1)){
            break;
        }
        
        curr_node = curr_node->next;
        counter++;
    }
    Node_int* tmp = curr_node->next;
    curr_node->next = new_node;
    new_node->next = tmp;

}

void print_linkedlist__int(Node_int** head_ref){
    Node_int* curr_node = *head_ref;
    while (curr_node != NULL){
        printf("%d\n", curr_node->data);
        curr_node = curr_node->next;
    }
}

int main(int argc, char **argv){
    
    Node_int* head = NULL;
    push_node__int(&head, 2);
    push_node__int(&head, 45);
    push_node__int(&head, 23);
    push_node__int(&head, 55);
    insert_node_at_pos__int(&head, 33, 1);
    print_linkedlist__int(&head);
    return 0;
}