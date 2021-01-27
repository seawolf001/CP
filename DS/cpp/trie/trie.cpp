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
    bool deleteRecusively(string &s, int idx, TrieNode* parent) {
        if(idx == s.size())
            return false;
        auto itr = parent->keys.find(s[idx]);
        if(itr == parent->keys.end())
            return false;
        TrieNode* node = itr->second;
        deleteRecusively(s, idx+1, node); // delete child or next node
        --node->ref;
        if(node->ref == 0) {
            // delete node with ref count=0, ref=0 implies this node is not used in any other word.
            parent->keys.erase(s[idx]);
            delete node;
            node = nullptr;
        }
        return true;
    }

public:
    Trie(): root(new TrieNode()){}

    bool deleteItem(string s) {
        if(s.size() == 0)
            return false;
        return deleteRecusively(s, 0, root);
    }
    void insertItem(string s) {
        TrieNode* node = root;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(char &c:s) {
            if(node->keys.find(c) == node->keys.end())
                node->keys[c] = new TrieNode();
            node = node->keys[c];
            ++node->ref;
        }
        node->leaf = true;
    }
    bool search(string s) {
        TrieNode* node = root;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(char &c:s) {
            if(node->keys.find(c) == node->keys.end())
                return false;
            node = node->keys[c];
        }
        return node->leaf;
    }
    vector<string> startsWith(string prefix) {
        transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);
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
            auto f = q.front(); q.pop();
            TrieNode* curr = f.first;
            if(curr->leaf) {
                res.push_back(f.second);
            } else {
                for(auto it=curr->keys.begin(); it!=curr->keys.end(); it++) {
                    if(it->second != nullptr){
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
    vector<string> dictionary {
        "Jitu", "Jiten", "Jitendra", "jittu",
        "Maynk", "Mayank", "Mahesh", "Manyavar",
        "Pra", "pras", "Prass", "Prashsnt", "Prashant"
    };
    assert (t.deleteItem("random") == false);
    assert (t.search("random2") == false);
    assert (t.startsWith("j").size() == 0);

    for(string &word: dictionary)
        t.insertItem(word);

    for(string &word: dictionary)
        assert (t.search(word) == true);

    for(string word: t.startsWith("Ji"))
        cout << word << " ";
    cout << endl;

    vector<string> deleted; int n = dictionary.size();
    while(deleted.size() < n/2) {
        int idx = rand() % dictionary.size();
        string deleting = dictionary[idx];

        dictionary.erase(find(dictionary.begin(), dictionary.end(), deleting));

        if(t.deleteItem(deleting)){
            deleted.push_back(deleting);;
            cout << "Deleted `" << deleting << "` from the dictionary." << endl;
        } else {
            cout << "An attempt to delete " << deleting << " failed." << endl;
        }
    }

    for(string &word: deleted)
        assert (t.search(word) == false);

    return 0;
}

