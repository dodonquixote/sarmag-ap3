#include <stdio.h>      // library untuk printf, scanf
#include <stdlib.h>     // library untuk malloc, free

//////////////////////////////////////////////////
// 1. POINTER DEMO
//////////////////////////////////////////////////
void pointerDemo() {
    int x = 10;         // deklarasi variabel x dengan nilai 10
    int *p = &x;        // pointer p menyimpan alamat dari x

    printf("=== POINTER DEMO ===\n");  
    printf("Nilai x        : %d\n", x);     // cetak nilai x
    printf("Alamat x       : %p\n", &x);    // cetak alamat memori x
    printf("Pointer p      : %p\n", p);     // cetak isi pointer p (alamat x)
    printf("Isi *p         : %d\n", *p);    // cetak nilai yang ditunjuk p (yaitu x)
}

//////////////////////////////////////////////////
// 2. ARRAY & POINTER DEMO
//////////////////////////////////////////////////
void arrayPointerDemo() {
    int arr[5] = {1, 2, 3, 4, 5};    // array dengan 5 elemen
    int *p = arr;                    // pointer p menunjuk elemen pertama array

    printf("\n=== ARRAY & POINTER ===\n");

    for (int i = 0; i < 5; i++) {    // loop dari index 0 sampai 4
        printf("arr[%d] = %d | *(p+%d) = %d\n",
               i, arr[i],           // akses array biasa
               i, *(p + i));        // akses array via pointer arithmetic
    }
}

//////////////////////////////////////////////////
// 3. SINGLY LINKED LIST
//////////////////////////////////////////////////

// Struktur node untuk linked list
struct Node {
    int data;               // data yang disimpan
    struct Node *next;      // pointer ke node berikutnya
};

// Menyisipkan node baru di depan
void insertFront(struct Node **head, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node)); // alokasi memori node baru
    newNode->data = value;       // isi data
    newNode->next = *head;       // hubungkan node baru ke head lama
    *head = newNode;             // jadikan node baru sebagai head
}

// Menghapus node berdasarkan nilai tertentu
void deleteValue(struct Node **head, int value) {
    struct Node *temp = *head;   // pointer untuk traversal
    struct Node *prev = NULL;    // menyimpan node sebelumnya

    while (temp != NULL && temp->data != value) { // cari node dengan nilai yang dicari
        prev = temp;             // simpan node sebelumnya
        temp = temp->next;       // pindah ke node berikutnya
    }

    if (temp == NULL) return;    // jika tidak ditemukan, keluar

    if (prev == NULL) {          // jika node yang dihapus adalah head
        *head = temp->next;      // geser head ke node berikutnya
    } else {
        prev->next = temp->next; // lewati node yang dihapus
    }

    free(temp);                  // hapus memory node
}

// Menampilkan isi linked list
void displayList(struct Node *head) {
    printf("\n=== LINKED LIST ===\n");

    while (head != NULL) {       // traversal sampai NULL
        printf("%d -> ", head->data); // cetak data
        head = head->next;       // maju ke node berikutnya
    }

    printf("NULL\n");
}

//////////////////////////////////////////////////
// 4. STACK DENGAN ARRAY
//////////////////////////////////////////////////

#define MAX 10   // kapasitas maksimal stack

// Struktur stack
struct Stack {
    int data[MAX];     // array penyimpan data stack
    int top;           // index elemen paling atas
};

// Inisialisasi stack
void initStack(struct Stack *s) {
    s->top = -1;       // top = -1 artinya stack kosong
}

// Push data ke stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {         // cek jika penuh
        printf("Stack penuh!\n");
        return;
    }
    s->data[++s->top] = value;       // increment top, lalu simpan data
}

// Pop data dari stack
int pop(struct Stack *s) {
    if (s->top == -1) {              // cek jika kosong
        printf("Stack kosong!\n");
        return -1;
    }
    return s->data[s->top--];        // ambil data di top, lalu turunkan top
}

// Menampilkan stack
void displayStack(struct Stack *s) {
    printf("\n=== STACK ===\n");

    for (int i = s->top; i >= 0; i--) {  // cetak dari top ke bawah
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

//////////////////////////////////////////////////
// 5. QUEUE DENGAN LINKED LIST
//////////////////////////////////////////////////

// Struktur node untuk queue
struct QueueNode {
    int data;                   // data
    struct QueueNode *next;     // pointer ke node berikutnya
};

// Struktur queue utama
struct Queue {
    struct QueueNode *front;    // elemen paling depan
    struct QueueNode *rear;     // elemen paling belakang
};

// Inisialisasi queue
void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;  // queue kosong
}

// Enqueue: memasukkan data ke belakang queue
void enqueue(struct Queue *q, int value) {
    struct QueueNode *newNode = (struct QueueNode*) malloc(sizeof(struct QueueNode)); // buat node baru
    newNode->data = value;     // isi data
    newNode->next = NULL;      // node baru menjadi ujung (rear)

    if (q->rear == NULL) {     // jika queue masih kosong
        q->front = q->rear = newNode;  // front dan rear sama
        return;
    }

    q->rear->next = newNode;   // hubungkan node lama ke node baru
    q->rear = newNode;         // update rear ke node baru
}

// Dequeue: menghapus data dari depan queue
int dequeue(struct Queue *q) {
    if (q->front == NULL) {     // queue kosong
        printf("Queue kosong!\n");
        return -1;
    }

    struct QueueNode *temp = q->front; // simpan node yang akan dihapus
    int value = temp->data;            // ambil datanya

    q->front = q->front->next;         // geser front ke node berikutnya

    if (q->front == NULL)              // jika front kosong setelah dihapus
        q->rear = NULL;                // maka rear juga harus NULL

    free(temp);                        // hapus memori node

    return value;                      // kembalikan data
}

// Menampilkan isi queue
void displayQueue(struct Queue *q) {
    printf("\n=== QUEUE ===\n");

    struct QueueNode *temp = q->front; // mulai dari front
    while (temp != NULL) {             // loop sampai akhir
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
    pointerDemo();          // panggil demo pointer

    // ARRAY + POINTER
    arrayPointerDemo();     // panggil demo array dan pointer

    // LINKED LIST
    struct Node *head = NULL;   // head pertama kosong

    insertFront(&head, 10);     // sisipkan node 10 di depan
    insertFront(&head, 20);     // sisipkan node 20 di depan
    insertFront(&head, 30);     // sisipkan node 30 di depan
    displayList(head);          // tampilkan list

    deleteValue(&head, 20);     // hapus node dengan nilai 20
    displayList(head);          // tampilkan lagi

    // STACK DEMO
    struct Stack s;
    initStack(&s);              // inisialisasi stack

    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    displayStack(&s);           // tampilkan isi stack

    printf("Pop: %d\n", pop(&s)); // ambil elemen teratas
    displayStack(&s);

    // QUEUE DEMO
    struct Queue q;
    initQueue(&q);              // inisialisasi queue

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    displayQueue(&q);           // tampilkan isi queue

    printf("Dequeue: %d\n", dequeue(&q)); // keluarkan elemen terdepan
    displayQueue(&q);

    return 0;                   // program selesai
}
