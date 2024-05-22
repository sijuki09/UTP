#include <stdio.h>

#define MAX_STACK_SIZE 100

struct perubahan {
    char karakter[100];
    int ubah;
};

int isFull(int top) {
    return top == MAX_STACK_SIZE - 1;
}

int isEmpty(int top) {
    return top == -1;
}

void push(struct perubahan stack[], int *top) {
    if (isFull(*top)) {
        printf("Stack penuh, tidak bisa menambahkan data.\n");
    } else {
        (*top)++;
        printf("Masukkan karakter: ");
        scanf("%s", stack[*top].karakter);
        printf("Data berhasil dimasukkan ke dalam stack.\n");
    }
}

int pop(struct perubahan stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack kosong, tidak ada data untuk dikeluarkan.\n");
        return -1;
    } else {
        printf("karakter yang ingin diubah menjadi integer: %s\n", stack[*top].karakter);
        int temp = atoi(stack[*top].karakter);
        (*top)--;
        return temp;
    }
}

int main() {
    struct perubahan stack[MAX_STACK_SIZE];
    int top = -1;

    int pilih = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Masukkan data\n");
        printf("2. Ubah data menjadi integer\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                push(stack, &top);
                break;
            case 2: {
                int result = pop(stack, &top);
                if (result != -1)
                    printf("Nilai integer: %d\n", result);
                break;
            }
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilih != 3);

    return 0;
}
