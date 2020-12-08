class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return 0;
        return (ceil(log2(n)) == floor(log2(n)));
    }
};
