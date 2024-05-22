#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE][100];
    int top;
};

typedef struct Stack Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char* item) {
    if (isFull(stack)) {
        printf("Stack penuh, tidak dapat menambahkan item.\n");
        return;
    }
    strcpy(stack->items[++stack->top], item);
}

char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak ada item untuk diambil.\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

void divideAndPrint(Stack* mainStack) {
    Stack* stack1 = createStack();
    Stack* stack2 = createStack();
    Stack* stack3 = createStack();
    int size = (mainStack->top + 1) / 3;

    for (int i = 0; i < size; i++) {
        push(stack3, pop(mainStack));
        push(stack2, pop(mainStack));
        push(stack1, pop(mainStack));
    }

    printf("Isi Stack 1:\n");
    while (!isEmpty(stack1)) {
        printf("%s\n", pop(stack1));
    }
    printf("\n");

    printf("Isi Stack 2:\n");
    while (!isEmpty(stack2)) {
        printf("%s\n", pop(stack2));
    }
    printf("\n");

    printf("Isi Stack 3:\n");
    while (!isEmpty(stack3)) {
        printf("%s\n", pop(stack3));
    }
}

int main() {
    Stack* mainStack = createStack();
    
    push(mainStack, "String 1");
    push(mainStack, "String 2");
    push(mainStack, "String 3");
    push(mainStack, "String 4");
    push(mainStack, "String 5");
    push(mainStack, "String 6");

    divideAndPrint(mainStack);

    return 0;
}