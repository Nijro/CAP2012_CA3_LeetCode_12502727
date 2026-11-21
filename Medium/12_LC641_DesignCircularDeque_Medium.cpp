// LeetCode 641: Design Circular Deque
#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> buf;
    int front;
    int rear;
    int count;
    int cap;

public:
    MyCircularDeque(int k) : buf(k, 0), front(0), rear(k - 1), count(0), cap(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        buf[front] = value;
        ++count;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % cap;
        buf[rear] = value;
        ++count;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        --count;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + cap) % cap;
        --count;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : buf[front];
    }

    int getRear() {
        return isEmpty() ? -1 : buf[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == cap;
    }
};

int main() {
    MyCircularDeque dq(3);
    cout << "insertLast(1): " << dq.insertLast(1) << endl;   // 1
    cout << "insertLast(2): " << dq.insertLast(2) << endl;   // 1
    cout << "insertFront(3): " << dq.insertFront(3) << endl; // 1
    cout << "insertFront(4) when full (Expected 0): " << dq.insertFront(4) << endl;
    cout << "getRear (Expected 2): " << dq.getRear() << endl;
    dq.deleteLast();
    dq.insertFront(4);
    cout << "getFront (Expected 4): " << dq.getFront() << endl;
    return 0;
}