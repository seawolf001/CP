vector<vector<int> > Solution::fourSum(vector<int> &arr, int sum) {

//   unordered_map<int, pair<int,int>> hash;
//   unordered_map<int, pair<int,int>>::iterator it;
   int n =arr.size();
   sort(arr.begin(), arr.end());
   vector<vector<int>> res;
    for(int i=0;i<=n-4;i++){
        for(int j=i+1;j<=n-3;j++){
            int k=sum-(arr[i]+arr[j]);
            int l=j+1;
            int r=n-1;
            while(l<r){
                int p = arr[l]+arr[r];
                if(p<k)l++;
                else if(p>k)r--;
                else{
                    vector<int> v;
                      v.push_back(arr[i]);
                      v.push_back(arr[j]);
                      v.push_back(arr[l]);
                      v.push_back(arr[r]);
                      sort(v.begin(), v.end());
                      if(find(res.begin(), res.end(), v) == res.end())
                                 res.push_back(v);
                     l++;
                     r--;
                }
            }
        }
    }
   sort(res.begin(), res.end());
   return res;
}

