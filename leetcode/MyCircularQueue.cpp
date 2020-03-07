class MyCircularQueue {
private:
    vector<int> v;
    int length, begin, end;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        v.resize(k);
        length = 0;
        begin = 0;
        end = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (length < v.size()) {
            v[end] = value;
            end = (end + 1) % v.size();
            ++length;
            return true;
        } else {
            return false;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (length > 0) {
            begin = (begin + 1) % v.size();
            --length;
            return true;
        } else {
            return false;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        return length > 0 ? v[begin] : -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (length > 0) {
            return v[(end - 1 + v.size()) % v.size()];
        } else {
            return -1;
        }
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return length == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return length == v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
