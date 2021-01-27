#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool leaf;
    int ref;
    unordered_map<char, TrieNode*> keys;
    TrieNode(): ref(0), leaf(false), keys({}){}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(): root(new TrieNode()){}
    bool deleteItem(string s) {
        int n = s.size();
        if(n==0)
            return true;
        TrieNode* node = root;
        for(char &c: s) {
        if(node->keys.find(c) == node->keys.end())
            return false;
            node = node->keys[c];
        }
        if(!node->leaf)
            return false;
        --node->ref;
        if(node->ref==0) node->keys.erase(s[n-1]);//delete node, node=nullptr; //
        return true;
    }
    void insertItem(string s) {
        TrieNode* node = root;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(char &c:s) {
            if(node->keys.find(c) == node->keys.end())
                node->keys[c] = new TrieNode();
            node = node->keys[c];
        }
        node->leaf = true;
        ++node->ref;
    }
    bool search(string s) {
        TrieNode* node = root;
        for(char &c:s) {
            if(node->keys.find(c) == node->keys.end())
                return false;
            node = node->keys[c];
        }
        return node->leaf && node->ref!=0;
    }
    vector<string> startsWith(string prefix) {
        TrieNode* node = root;
        for(char &c:prefix) {
            if(node->keys.find(c) == node->keys.end())
                return {};
            node = node->keys[c];
        }
        vector<string> res;
        queue<pair<TrieNode*, string>> q;
        q.push(make_pair(node, prefix));
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                auto f = q.front(); q.pop();
                if(f.first->leaf)
                    res.push_back(f.second);
                else {
                    auto keys = f.first->keys;
                    for(auto it=keys.begin(); it!=keys.end(); it++) {
                        if(it->second != nullptr)
                            q.push(make_pair(it->second, f.second + it->first));
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Trie t;
    vector<string> words{"Jitendra", "Jitendra Kumar", "Kumar", "Shivam", "shyam"};
    for(string &w: words)
        t.insertItem(w);
    cout << t.search("jitendra") << endl;
    for(string& w: t.startsWith("sh")) cout << w << " ";
    cout << endl;
    // t.deleteItem("shivam");
    // for(string& w: t.startsWith("sh")) cout << w << " ";
    return 0;
}

