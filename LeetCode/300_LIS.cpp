class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        int L[n];
        memset(L, 0, sizeof L);
        L[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && L[j]>L[i])
                    L[i]=L[j];
            }
            L[i]++;
        }
        int LIS = INT_MIN;
        for(int x: L){
            LIS = max(x,LIS);
        }
        return LIS;
    }
};
