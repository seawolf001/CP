from functools import cmp_to_key

def comparator(a, b):
    x = str(a) + str(b)
    y = str(b) + str(a)
    return (x+y) > (y+x)

def largest(arr):
    arr.sort(key=cmp_to_key(comparator))
    ans = "".join([str(x) for x in arr])
    return int(ans)

def run_tests():
    assert largest([54, 546, 548, 60]) == 6054854654

if __name__ == '__main__':
    run_tests()
