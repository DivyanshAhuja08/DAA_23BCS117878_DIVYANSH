
#include <iostream>
using namespace std;

// ------------------ DOUBLY LINKED LIST -------------------
class DoublyList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(NULL), next(NULL) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyList() : head(NULL), tail(NULL) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }

    void display() {
        Node* curr = head;
        cout << "Doubly List: ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// ------------------ CIRCULAR LINKED LIST -------------------
class CircularList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node* tail;

public:
    CircularList() : tail(NULL) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* head = tail->next;
        if (head == tail) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            tail = NULL;
        } else {
            cout << "Deleted: " << head->data << endl;
            tail->next = head->next;
            delete head;
        }
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* curr = tail->next;
        if (curr == tail) {
            cout << "Deleted: " << tail->data << endl;
            delete tail;
            tail = NULL;
        } else {
            while (curr->next != tail) {
                curr = curr->next;
            }
            cout << "Deleted: " << tail->data << endl;
            curr->next = tail->next;
            delete tail;
            tail = curr;
        }
    }

    void display() {
        if (!tail) {
            cout << "Circular List is empty\n";
            return;
        }
        Node* curr = tail->next;
        cout << "Circular List: ";
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << endl;
    }
};

// ------------------ MAIN -------------------
int main() {
    DoublyList dList;
    dList.insertAtBeginning(10);
    dList.insertAtEnd(20);
    dList.insertAtBeginning(5);
    dList.display();
    dList.deleteAtBeginning();
    dList.deleteAtEnd();
    dList.display();

    CircularList cList;
    cList.insertAtEnd(1);
    cList.insertAtEnd(2);
    cList.insertAtBeginning(0);
    cList.display();
    cList.deleteAtBeginning();
    cList.deleteAtEnd();
    cList.display();

    return 0;
}
