int Solution::threeSumClosest(vector<int> &arr, int sum) {
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int diff = INT_MAX ; int s=0;
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k = n-1;
        while(j<k){
            int _s = arr[i]+arr[j]+arr[k];
            int _diff = abs(arr[i]+arr[j]+arr[k]-sum);
            if(_diff == 0) return _s;
            if(_diff < diff){
                diff = _diff;
                s=_s;
            }
            if(_s < sum) j++;
            else if(_s > sum) k--;
        }
    }
    return s;
}

