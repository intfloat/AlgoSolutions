class MyCircularDeque {
private:
    vector<int> data;
    int front, length;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data.resize(k);
        front = length = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        if (!isEmpty()) {
            front = (front - 1 + data.size()) % data.size();
        }
        data[front] = value;
        ++length;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        int rear = isEmpty() ? front : (front + length) % data.size();
        data[rear] = value;
        ++length;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % data.size();
        --length;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        --length;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        int rear = (front + length - 1 + data.size()) % data.size();
        return data[rear];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return length == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return length == data.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
