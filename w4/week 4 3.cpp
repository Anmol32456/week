#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue overflow!\n";
            return;
        }
        rear++;
        arr[rear] = value;
    }

    // Dequeue operation
    void dequeue() {
        if (front > rear) {
            cout << "Queue underflow!\n";
            return;
        }
        front++;
    }

    // Display the queue
    void display() {
        if (front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Reverse first K elements
    void reverseFirstK(int k) {
        if (k > rear - front + 1 || k < 0) {
            cout << "Invalid K value.\n";
            return;
        }
        // Reverse first K elements
        for (int i = 0; i < k / 2; i++) {
            int temp = arr[front + i];
            arr[front + i] = arr[front + k - 1 - i];
            arr[front + k - 1 - i] = temp;
        }
        cout << "First " << k << " elements reversed.\n";
    }

    // Interleave first half with second half
    void interleaveQueue() {
        int n = rear - front + 1;
        if (n % 2 != 0) {
            cout << "Cannot interleave an odd-sized queue.\n";
            return;
        }

        int half = n / 2;
        int temp[SIZE];

        // Copy first half and interleave with second
        int index = 0;
        for (int i = 0; i < half; i++) {
            temp[index++] = arr[front + i];
            temp[index++] = arr[front + i + half];
        }

        for (int i = 0; i < n; i++) {
            arr[front + i] = temp[i];
        }

        cout << "Queue interleaved successfully.\n";
    }
};

int main() {
    Queue q;
    int choice, value, k;

    cout << "Queue Implementation using Array (no STL)\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Reverse first K elements\n";
        cout << "5. Interleave first and second half\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Enter value of K: ";
            cin >> k;
            q.reverseFirstK(k);
            break;
        case 5:
            q.interleaveQueue();
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

