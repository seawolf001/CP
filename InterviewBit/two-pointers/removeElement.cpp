int Solution::removeElement(vector<int> &arr, int x) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=x) arr[j++] = arr[i];
    }
    return j;
}

