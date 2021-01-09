/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
It's a common way to implement a queue in functional programming languages with purely functional (immutable, but sharing structure) lists (e.g. Clojure, Haskell, Erlang...):

use a pair of lists to represent a queue where elements are in FIFO order in the first list and in LIFO order in the second list
enqueue to the queue by prepending to the second list
dequeue from the queue by taking the first element of the first list
if the first list is empty: reverse the second list and replace the first list with it, and replace the second list with an empty list
(all operations return the new queue object in addition to any possible return values)

The point is that adding (removing) an element to (from) the front of a purely functional list is O(1) and the reverse operation which is O(n) is amortised over all the dequeues, so it's close to O(1), thereby giving you a ~O(1) queue implementation with immutable data structures.
 * */

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> in, out;
    MyQueue() { }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        out.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

