class MedianFinder {
private:
    priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int> > mn_heap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (mx_heap.empty()) mx_heap.push(num);
        else if (num <= mx_heap.top()) mx_heap.push(num);
        else mn_heap.push(num);
        while (mx_heap.size() > mn_heap.size() + 1) {
            mn_heap.push(mx_heap.top());
            mx_heap.pop();
        }
        while (mn_heap.size() > mx_heap.size()) {
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (mn_heap.size() == mx_heap.size()) {
            return (1.0 * mn_heap.top() + mx_heap.top()) / 2.0;
        }
        else return 1.0 * mx_heap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
