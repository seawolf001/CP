#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_set<int> vis;
    int dfs(Employee* e, unordered_map<int, Employee*> &mp) {
        for(int &sub: e->subordinates)
            e->importance += dfs(mp[sub], mp);
        return e->importance;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(Employee* e: employees)
            mp[e->id] = e;
        dfs(mp[id], mp);
        return mp[id]->importance;
    }
};

