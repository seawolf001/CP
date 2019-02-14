int Solution::longestConsecutive(const vector<int> &arr) {
    unordered_set<int>s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    int m=0;
    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        if(s.find(x-1)==s.end()){
            while(s.find(x)!=s.end()) x++;
            m = max(m, x-arr[i]);
        }
    }
    return m;
}

