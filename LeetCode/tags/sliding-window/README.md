#### A generic pattern [taken from [link](https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems)] which can be followed to implement sliding-windows problems.

```cpp
    int findSubstring(string s){
        vector<int> map(128,0); // or unordered_map
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){
            if(map[s[end++]]-- ?){  /* modify counter here */ }
            while(/* counter condition */){
                 /* update d here if finding minimum*/
                //increase begin to make it invalid/valid again
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }
            /* update d here if finding maximum*/
        }
        return d;
    }
```

### Some useful notes, mostly from discussion forum:

* **Sliding Window for Beginners [Problems | Template | Sample Solutions]**
    * https://leetcode.com/discuss/general-discussion/657507/Sliding-Window-for-Beginners-Problems-or-Template-or-Sample-Solutions
* **Leetcode: Hard, 76. Minimum Window Substring**
    * https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
* **Leetcode: Hard, 992. Subarrays with K Different Integers**
    * https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window
    * https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window

