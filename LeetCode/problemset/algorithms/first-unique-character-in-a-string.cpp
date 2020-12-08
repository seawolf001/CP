class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26,0);
        for (int i = 0;i<s.size();i++){
            vec[s[i] - 'a']++;
        }
        
        for (int i = 0;i<s.size();i++){
            if(vec[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
