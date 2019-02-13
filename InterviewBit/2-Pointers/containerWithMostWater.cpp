int Solution::maxArea(vector<int> &arr) {
    int _min = 0;
    int n=arr.size();
    if(n==1) return 0;
    int _max = INT_MIN;
    int l = 0;
    int r = n-1;
    while(l<r){
        _min = min(arr[l], arr[r]);
        _max = max(_max, _min * (r-l));
        if(arr[l]<arr[r]) l++;
        else r--;
    }
    return _max;
}

