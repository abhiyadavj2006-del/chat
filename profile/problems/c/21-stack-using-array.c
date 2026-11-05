// Advanced C - Stack using array
#include <stdio.h>
#define MAX 100
int stack[MAX], top = -1;
void push(int value) {
    if (top == MAX - 1) { printf("Stack overflow\n"); return; }
    stack[++top] = value;
}
int pop() {
    if (top == -1) { printf("Stack underflow\n"); return -1; }
    return stack[top--];
}
void display() {
    int i;
    if (top == -1) { printf("Stack is empty\n"); return; }
    for (i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter value: "); scanf("%d", &value); push(value); }
        else if (choice == 2) printf("Popped: %d\n", pop());
        else if (choice == 3) display();
        else break;
    }
    return 0;
}
