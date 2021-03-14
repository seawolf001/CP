

def count_ways(N):
    count = 0
    n = 2
    while 2*N+n-n**2 > 0:
        a = (2*N+n-n**2)/(2*n)
        if a == int(a):
            count += 1
        n += 1
    return count


print(count_ways(10))
print(count_ways(100))
print(count_ways(15))
