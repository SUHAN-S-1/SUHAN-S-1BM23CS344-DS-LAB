#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CircularQueue {
    int *arr;
    int front;
    int rear;
};

void initQueue(struct CircularQueue *q) {
    q->arr = (int *)malloc(MAX * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(struct CircularQueue *q) {
    return q->front == -1;
}

void insert(struct CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

int delete(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element\n");
        return -1;
    } else {
        int deletedValue = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return deletedValue;
    }
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to display\n");
    } else {
        printf("Queue contents: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
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
