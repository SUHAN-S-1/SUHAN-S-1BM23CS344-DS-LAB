#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createLinkedList(struct Node** head) {
    *head = NULL;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = head2;
}

int main() {
    struct Node* list1;
    struct Node* list2;
    int choice, value;

    createLinkedList(&list1);
    createLinkedList(&list2);

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at End (List 1)\n");
        printf("2. Insert at End (List 2)\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &value);
                insertAtEnd(&list1, value);
                break;
            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &value);
                insertAtEnd(&list2, value);
                break;
            case 3:
                display(list1);
                break;
            case 4:
                display(list2);
                break;
            case 5:
                sortList(list1);
                printf("List 1 sorted.\n");
                break;
            case 6:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;
            case 7:
                concatenateLists(&list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
