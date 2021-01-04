/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> tracker;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(tracker.find(node) == tracker.end()) {
            tracker[node] = new Node(node->val);
            for(auto x: node->neighbors) {
                tracker[node]->neighbors.push_back(cloneGraph(x));
            }
        }
        return tracker[node];
    }
};
