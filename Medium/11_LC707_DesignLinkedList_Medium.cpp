// LeetCode 707: Design Linked List
#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v, Node* n = nullptr) : val(v), next(n) {}
    };
    Node* head;
    int size;

public:
    MyLinkedList() : head(new Node(-1)), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* pred = head;
        for (int i = 0; i < index; ++i) pred = pred->next;
        return pred->next->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }
    void addAtTail(int val) { addAtIndex(size, val); }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* pred = head;
        for (int i = 0; i < index; ++i) pred = pred->next;
        pred->next = new Node(val, pred->next);
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* pred = head;
        for (int i = 0; i < index; ++i) pred = pred->next;
        Node* toDelete = pred->next;
        pred->next = toDelete->next;
        delete toDelete;
        --size;
    }

    ~MyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2); // 1 -> 2 -> 3
    cout << "get(1) (Expected 2): " << list.get(1) << endl;
    list.deleteAtIndex(1); // 1 -> 3
    cout << "get(1) after delete (Expected 3): " << list.get(1) << endl;
    cout << "get(5) invalid index (Expected -1): " << list.get(5) << endl;
    return 0;
}