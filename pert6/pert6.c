#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////
// 1. POINTER DEMO
//////////////////////////////////////////////////
void pointerDemo() {
    int x = 10;
    int *p = &x;

    printf("=== POINTER DEMO ===\n");
    printf("Nilai x        : %d\n", x);
    printf("Alamat x       : %p\n", &x);
    printf("Pointer p      : %p\n", p);
    printf("Isi *p         : %d\n", *p);
}

//////////////////////////////////////////////////
// 2. ARRAY & POINTER
//////////////////////////////////////////////////
void arrayPointerDemo() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr; // arr menunjuk ke elemen pertama

    printf("\n=== ARRAY & POINTER ===\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d | *(p+%d) = %d\n", i, arr[i], i, *(p + i));
    }
}

//////////////////////////////////////////////////
// 3. LINKED LIST: INSERT FRONT, DELETE VALUE, DISPLAY
//////////////////////////////////////////////////
struct Node {
    int data;
    struct Node *next;
};

void insertFront(struct Node **head, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void deleteValue(struct Node **head, int value) {
    struct Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        *head = temp->next; 
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void displayList(struct Node *head) {
    printf("\n=== LINKED LIST ===\n");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//////////////////////////////////////////////////
// 4. STACK USING ARRAY
//////////////////////////////////////////////////
#define MAX 10

struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack penuh!\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack kosong!\n");
        return -1;
    }
    return s->data[s->top--];
}

void displayStack(struct Stack *s) {
    printf("\n=== STACK ===\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

//////////////////////////////////////////////////
// 5. QUEUE USING LINKED LIST
//////////////////////////////////////////////////
struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, int value) {
    struct QueueNode *newNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue kosong!\n");
        return -1;
    }

    struct QueueNode *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return value;
}

void displayQueue(struct Queue *q) {
    printf("\n=== QUEUE ===\n");
    struct QueueNode *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//////////////////////////////////////////////////
// MAIN PROGRAM
//////////////////////////////////////////////////
int main() {

    // POINTER
    pointerDemo();

    // ARRAY & POINTER
    arrayPointerDemo();

    // LINKED LIST
    struct Node *head = NULL;
    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    displayList(head);

    deleteValue(&head, 20);
    displayList(head);

    // STACK
    struct Stack s;
    initStack(&s);
    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    displayStack(&s);
    printf("Pop: %d\n", pop(&s));
    displayStack(&s);

    // QUEUE
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    displayQueue(&q);
    printf("Dequeue: %d\n", dequeue(&q));
    displayQueue(&q);

    return 0;
}
