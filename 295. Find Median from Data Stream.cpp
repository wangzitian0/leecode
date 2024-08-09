/*
use two heap to store the max size/2 nums and min size/2 nums.
idea1. sz%2==1, add it to two structure, 1. both pop and cache it 2. cmp and push to two.
idea2. sz%2==1 store it with another variable. // I used this.
*/
class MedianFinder {
private:
    priority_queue<int> smallerHeap; // store num[i]
    priority_queue<int> largerHeap;  // store -num[i]
    int sz = 0;
    int mid = 0;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (sz == 0) {
            mid = num;
        } else if (sz % 2 == 0) {
            if (smallerHeap.top() > num) {
                mid = smallerHeap.top();
                smallerHeap.pop();
                smallerHeap.push(num);
            } else if (-largerHeap.top() < num) {
                mid = -largerHeap.top();
                largerHeap.pop();
                largerHeap.push(-num);
            } else {
                mid = num;
            }
        } else {
            if (mid < num) {
                smallerHeap.push(mid);
                largerHeap.push(-num);
            } else {
                smallerHeap.push(num);
                largerHeap.push(-mid);
            }
        }
        sz++;
    }

    double findMedian() {
        if (sz % 2 != 0) {
            return mid * 1.0;
        } else {
            return (smallerHeap.top() - largerHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */