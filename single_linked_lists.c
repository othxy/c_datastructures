# include <stdio.h>
# include <stdlib.h>

typedef struct Node__int {
    int data;
    struct Node__int* next;
} Node__int;

void erase_linkedlist__int(Node__int** head_ref){
    Node__int* prev = *head_ref;
 
    while (*head_ref)
    {
        *head_ref = (*head_ref)->next;
        free(prev);
        prev = *head_ref;
    }
}

void push_node__int(Node__int** head_ref, int data){
    Node__int* new_node = (Node__int*) malloc(sizeof(Node__int));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int len_linkedlist__int(Node__int** head_ref){
    Node__int* curr_node = *head_ref;
    int len = 0;
    while (curr_node != NULL){
        len++;
    }
    return len;
}

void append_node(Node__int** head_ref, int data){
    Node__int* new_node = (Node__int*)malloc(sizeof(Node__int));
    new_node->data = data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        Node__int* curr_node = *head_ref;
            
        while (curr_node->next != NULL){
            curr_node = curr_node->next;
        }
        
        curr_node->next = new_node;
    }

}

void insert_node_at_pos__int(Node__int** head_ref, int data, int pos){
    
    if (pos < 2 || *head_ref == NULL){
        push_node__int(head_ref, data);
    }
    else{
        Node__int* new_node = (Node__int*)malloc(sizeof(Node__int));
        new_node->data = data;
        
        Node__int* curr_node = *head_ref;

        int counter = 1;
        while (curr_node->next != NULL){
            if (counter == pos-1){
                break;
            }
            curr_node = curr_node->next;        
            counter++;
        }
        
        if (pos > counter+1){
            new_node->next = NULL;
            curr_node->next = new_node;
        }
        else {
            curr_node->next = new_node;
            new_node->next = curr_node->next;
        }
    }
}

void print_linkedlist__int(Node__int** head_ref){
    Node__int* curr_node = *head_ref;
    while (curr_node != NULL){
        printf("%d\n", curr_node->data);
        curr_node = curr_node->next;
    }
}

int main(int argc, char **argv){
    
    Node__int* head = NULL;
    //push_node__int(&head, 2);
    //push_node__int(&head, 45);
    //push_node__int(&head, 23);
    push_node__int(&head, 55);
    //insert_node_at_pos__int(&head, 33, 25);
    append_node(&head, 77);
    //erase_linkedlist__int(&head);
    print_linkedlist__int(&head);
    return 0;
}