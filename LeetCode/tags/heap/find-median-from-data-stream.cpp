#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

class MedianFinder {
private:
    priority_queue<int> q1; // left half: max heap
    priority_queue<int, vector<int>, greater<int>> q2; // right half: min heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        q1 = priority_queue<int>();
        q2 = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num) {
        if(q1.empty() || q1.top() > num)
            q1.push(num);
        else
            q2.push(num);
        // balance the 2 pqs
        if(q1.size() > q2.size()+1) {
            q2.push(q1.top());
            q1.pop();
        } else if(q1.size()+1 < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }
    }

    double findMedian() {
        if(q1.size() > q2.size())
            return q1.top();
        else if(q1.size() < q2.size())
            return q2.top();
        return q1.size() == 0 ? 0 : (q1.top() + q2.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */




