// LeetCode 225: Implement Stack using Queues
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    cout << "Top (Expected 2): " << st.top() << endl;
    cout << "Pop (Expected 2): " << st.pop() << endl;
    cout << "Empty (Expected 0): " << st.empty() << endl;
    st.pop();
    cout << "Empty after popping all (Expected 1): " << st.empty() << endl;
    return 0;
}