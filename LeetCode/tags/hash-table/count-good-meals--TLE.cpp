#define MOD 1000000007
class Solution {
public:
    int countPairs(vector<int>& del) {
        multiset<int> mset;
        long count=0;

        for(int i =0;i<=21;i++){
            int target = pow(2,i);
            for(int n:del){
                int complement = target-n;

                if(mset.find(complement)!=mset.end())
                    count= (count+ mset.count(complement));

                mset.insert(n);
            }
            mset.clear();
        }

        return count;
    }
};
