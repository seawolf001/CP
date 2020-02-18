from collections import defaultdict

def findSubarraySum(arr, n, SUM):
    """
    """
    ans = 0
    sumdict = defaultdict(int)
    curr = 0
    for i in range(n):
        curr += arr[i]
        if curr == SUM:
            ans += 1
        if (curr - SUM) in sumdict:
            ans += sumdict[curr-SUM]
        sumdict[curr] += 1
    return ans

def passTests():
    """
    Returns True if all tests pass else False
    """
    passing = True

    arr = [10, 2, -2, -20, 10]
    SUM = -10
    passing &= findSubarraySum(arr, len(arr), SUM) == 3

    arr = [9, 4, 20, 3, 10, 5]
    SUM = 33
    passing &= findSubarraySum(arr, len(arr), SUM) == 2

    return passing

if __name__ == '__main__':
    if passTests():
        print('All Tests are passing.')
    else:
        print('Some tests are failing.')
