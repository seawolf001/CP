vector<vector<int> > Solution::anagrams(const vector<string> &arr) {
    unordered_map<string, int> hash;
    vector<vector<int>> res;
    for(int i=0;i<arr.size();i++){
        string s=arr[i];
        sort(s.begin(), s.end());   
        unordered_map<string, int>::iterator it;
        it=hash.find(s);
        if(it!=hash.end()){
            vector<int> v;
            v.push_back(it->second);
            v.push_back(i+1);
            res.push_back(v);
        } else{
            hash[s]=i+1;
        }
    }
    return res;
}

