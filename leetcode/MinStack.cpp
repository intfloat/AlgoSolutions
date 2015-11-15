class MinStack {
public:
    stack<int> data;
    stack<int> mn;
    void push(int x) {
        data.push(x);
        if (mn.empty() || mn.top() >= x) mn.push(x);
    }

    void pop() {
        if (data.top() == mn.top()) mn.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mn.top();
    }
};
