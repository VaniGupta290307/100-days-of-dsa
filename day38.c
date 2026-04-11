#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (front == -1) return 0;
    return (rear - front + 1);
}

// push_front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// front element
int get_front() {
    if (empty()) return -1;
    return deque[front];
}

// rear element
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

// display
void display() {
    if (empty()) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
}

// reverse
void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++; j--;
    }
}

// sort (simple bubble sort)
void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = front; j < rear; j++) {
            if (deque[j] > deque[j + 1]) {
                int temp = deque[j];
                deque[j] = deque[j + 1];
                deque[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Example operations (you can modify input style if needed)

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    pop_front();   // removes 5
    pop_back();    // removes 30

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    display();

    return 0;
}
