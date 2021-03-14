from math import sqrt

def countLatticePoints(r):
    if r <= 0:
        return 0
    ans = 4
    for x in range(1, r):
        y2 = r**2 - x**2
        p = int(sqrt(y2))
        if p*p == y2:
            ans += 4
    return ans

def run_tests():
    assert countLatticePoints(5) == 12

if __name__ == '__main__':
    run_tests()
    print(countLatticePoints(5))

