#include <iostream>
using namespace std;

#define SIZE 10

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == SIZE - 1) {
            cout << "Stack is full!\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        top--;
    }

    // Find middle element
    void findMiddle() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        int mid = top / 2;
        cout << "Middle element: " << arr[mid] << endl;
    }

    // Reverse bottom half of the stack
    void reverseBottomHalf() {
        if (top < 1) {
            cout << "Not enough elements.\n";
            return;
        }
        int mid = (top + 1) / 2;
        for (int i = 0; i < mid / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[mid - 1 - i];
            arr[mid - 1 - i] = temp;
        }
        cout << "Bottom half reversed.\n";
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int value;

    cout << "Enter up to 10 values to push into the stack:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value #" << i + 1 << " (or -1 to stop): ";
        cin >> value;
        if (value == -1) break;
        s.push(value);
    }

    cout << "\nBefore Reversing:\n";
    s.display();

    s.findMiddle();
    s.reverseBottomHalf();

    cout << "\nAfter Reversing Bottom Half:\n";
    s.display();

    return 0;
}

