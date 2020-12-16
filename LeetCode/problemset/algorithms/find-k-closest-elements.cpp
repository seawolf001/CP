class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> res;
        int idx=n-1;
        while(idx>=0 && arr[idx]>x) {
            idx--;
        }
        int count=0, i=idx, j=idx+1;
        while(count<k) {
            int p=INT_MIN,q=INT_MAX;
            if(i>=0) p = arr[i];
            if(j < n) q = arr[j];
            if(p!=INT_MIN && q!=INT_MAX) {
                if(x-p<=q-x) {
                    res.push_back(arr[i--]);
                } else {
                    res.push_back(arr[j++]);
                }
            } else if(p!=INT_MIN) {
                res.push_back(arr[i--]);
            } else {
                res.push_back(arr[j++]);
            }
            count++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
