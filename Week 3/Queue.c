#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int *arr;
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->arr = (int *)malloc(MAX * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void insert(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->arr[++(q->rear)] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

int delete(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element\n");
        return -1;  // Indicates error
    } else {
        int deletedValue = q->arr[q->front++];
        return deletedValue;
    }
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
    } else {
        printf("Queue contents: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                value = delete(&q);
                if (value != -1) {
                    printf("Deleted %d from the queue\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting the program.\n");
                free(q.arr);
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
