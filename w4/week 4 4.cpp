#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at given position (1-based)
    void insertAtPos(int pos, int val) {
        if (pos == 1) {
            insertAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Print list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Detect and remove loop
    void detectAndRemoveLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Loop found, removing...\n";
                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = NULL;
                return;
            }
        }
        cout << "No loop found.\n";
    }

    // Find nth node from end
    void findNthFromEnd(int n) {
        Node* first = head;
        Node* second = head;

        for (int i = 0; i < n; i++) {
            if (second == NULL) {
                cout << "Less than " << n << " nodes\n";
                return;
            }
            second = second->next;
        }

        while (second != NULL) {
            first = first->next;
            second = second->next;
        }

        cout << "Nth node from end is: " << first->data << endl;
    }

    // Reverse in groups of K
    Node* reverseK(Node* head, int k) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if (next != NULL)
            head->next = reverseK(next, k);

        return prev;
    }

    void reverseInGroups(int k) {
        head = reverseK(head, k);
    }

    // For testing loop detection
    void createLoop() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head->next; // Create loop
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Initial list:\n";
    list.printList();

    cout << "Inserting 99 at position 3:\n";
    list.insertAtPos(3, 99);
    list.printList();

    cout << "3rd node from end:\n";
    list.findNthFromEnd(3);

    cout << "Reversing in groups of 2:\n";
    list.reverseInGroups(2);
    list.printList();

    cout << "Creating and detecting loop:\n";
    list.createLoop();
    list.detectAndRemoveLoop();
    list.printList();

    return 0;
}

