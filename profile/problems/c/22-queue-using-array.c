// Advanced C - Queue using array
#include <stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) { printf("Queue overflow\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear) { printf("Queue underflow\n"); return -1; }
    return queue[front++];
}
void display() {
    int i;
    if (front == -1 || front > rear) { printf("Queue is empty\n"); return; }
    for (i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) { printf("Enter value: "); scanf("%d", &value); enqueue(value); }
        else if (choice == 2) printf("Dequeued: %d\n", dequeue());
        else if (choice == 3) display();
        else break;
    }
    return 0;
}
