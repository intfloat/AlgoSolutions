class Stack {
private:
    deque<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push_front(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop_front();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
