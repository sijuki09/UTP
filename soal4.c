#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char nama[50];
    char pesanan[50];
} Pengunjung;

typedef struct {
    Pengunjung data;
} Node;

typedef struct {
    int front, rear, count;
    Node nodes[MAX_SIZE];
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->count == 0;
}

int isFull(Queue* queue) {
    return queue->count == MAX_SIZE;
}

void enqueue(Queue* queue, Pengunjung pengunjung) {
    if (isFull(queue)) {
        printf("Antrian penuh, pengunjung tidak dapat ditambahkan\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->nodes[queue->rear].data = pengunjung;
    queue->count++;
}

Pengunjung dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong\n");
        exit(1);
    }
    Pengunjung removed = queue->nodes[queue->front].data;
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;
    return removed;
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong\n");
        return;
    }
    printf("Antrian pengunjung kafe:\n");
    int i = queue->front;
    int count = 0;
    while (count < queue->count) {
        printf("%s - Pesanan: %s\n", queue->nodes[i].data.nama, queue->nodes[i].data.pesanan);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
}

int main() {
    Queue* queue = createQueue();
    int choice;
    Pengunjung pengunjung;

    do {
        printf("\nMenu:\n");
        printf("1. Pengunjung masuk antrian\n");
        printf("2. Pengunjung selesai dilayani\n");
        printf("3. Tampilkan antrian\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nama pengunjung: ");
                scanf("%s", pengunjung.nama);
                printf("Masukkan pesanan: ");
                scanf("%s", pengunjung.pesanan);
                enqueue(queue, pengunjung);
                printf("Pengunjung telah ditambahkan ke dalam antrian\n");
                break;
            case 2:
                if (!isEmpty(queue)) {
                    Pengunjung selesai = dequeue(queue);
                    printf("Pengunjung %s dengan pesanan %s telah selesai dilayani dan keluar antrian\n", selesai.nama, selesai.pesanan);
                } else {
                    printf("Antrian kosong\n");
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Keluar dari program\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    } while (choice != 4);

    return 0;
}