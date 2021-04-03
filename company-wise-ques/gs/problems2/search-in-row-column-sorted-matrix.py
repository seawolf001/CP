
def findX(arr, X):
    '''
    '''
    n = len(arr)
    if X < arr[0][0] or X > arr[n-1][n-1]:
        return (None, None)
    i,j = 0, n-1
    while i < n and j >= 0:
        if arr[i][j] == X:
            return (i,j)
        elif arr[i][j] < X:
            i += 1
        elif arr[i][j] > X:
            j -= 1
    return (None, None)

def main():
    allTestsPassing = True

    matrix = [
        [10, 20, 30, 40],
        [15, 25, 35, 45],
        [27, 29, 37, 48],
        [32, 33, 39, 50]
    ]
    X = 29
    allTestsPassing &= findX(matrix, X) == (2,1)

    X = 100
    allTestsPassing &= findX(matrix, X) == (None,None)

    if allTestsPassing:
        print('All tests are passing.')
    else:
        print('Did not pass all the tests.')

if __name__ == '__main__':
    main()

