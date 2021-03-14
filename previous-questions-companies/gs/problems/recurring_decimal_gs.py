from sys import argv

def recurring_decimal(n, d):
    if d==0:
        raise Exception('Divide by Zero is not allowed.')
    if n==0:
        return 0
    if n*d < 0:
        negative = True
    else:
        negative = False
    if n%d==0:
        return str(n/d)
    n = abs(n)
    d = abs(d)

    result = ""
    result += str(n//d) + "."

    tracker = []

    while True:
        r = n % d
        n = r * 10
        q = n // d
        if (n,q) not in tracker:
            tracker.append((n, q))
        else:
            idx = tracker.index((n, q))
            for x in tracker[:idx]:
                result += str(x[1])
            result += "("
            for x in tracker[idx:]:
                result += str(x[1])
            result += ")"
            break;
    return result;

if __name__ == '__main__':
    if len(argv) > 2:
        print (argv[1], argv[2])
        print(recurring_decimal(int(argv[1]), int(argv[2])))
    else:
        # DEFAULT
        print(recurring_decimal(1,7))
