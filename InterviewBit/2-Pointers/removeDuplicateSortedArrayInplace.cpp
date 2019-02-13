int Solution::removeDuplicates(vector<int> &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int j=0;
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i]!=arr[i+1]){
            arr[j++]=arr[i];   
        }
    }
    arr[j++] = arr[n-1];
    return j;
}

