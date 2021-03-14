
from collections import defaultdict

def RLE(string):
    """
    Returns a run length encoding of the given string.
    """
    ans = ""
    n = len(string)
    i = 0
    while i < n:
        count = 1
        while i < n-1 and string[i] == string[i+1]:
            count +=1
            i += 1
        ans += string[i] + str(count)
        i += 1
    return ans

def main():
    allTestsPassing = True

    allTestsPassing &= RLE('wwwwaaadexxxxxxywww') == 'w4a3d1e1x6y1w3'
    allTestsPassing &= RLE('geeksforgeeks') == 'g1e2k1s1f1o1r1g1e2k1s1'

    if allTestsPassing:
        print('All Tests are passing.')
    else:
        print('Did not pass all the tests.')

if __name__ == '__main__':
    main()

