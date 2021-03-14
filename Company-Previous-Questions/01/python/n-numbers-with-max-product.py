'''
Name : Jitendra Kumar
Email: jitendra.iitp@gmail.com
'''

def pick_numbers_when_N_is_even(arr, length, N):
    '''
    Handler when N is an even number
    '''
    picked = []
    N = N >> 1 # N = N/2 since I will be choosing the elements in pair of 2
    right = length - 1
    left = 0
    for k in range(N):
        left_product = arr[left] * arr[left+1]
        right_product = arr[right] * arr[right-1]
        if left_product > right_product:
            # Pick 2 numbers from left margin.
            picked.extend([arr[left], arr[left+1]])
            left += 2
        else:
            # Pick 2 numbers from right margin.
            picked.extend([arr[right], arr[right-1]])
            right -= 2
    return picked

def pick_N_numbers(arr, length, N):
    '''
    Pick N numbers such that their product is maximum.
    Form a list of such numbers and return.
    '''
    if N == 0:
        error = "No need to pick any number as expected number of elements to be choosen is 0"
        return error, None

    if N > length:
        error = "Number of items can not be greater than total number of elements present in array"
        return error, None

    arr.sort() # sort the array in ascending order

    if N & 1:
        # When number of elements to be choosen is ODD
        j = length - 1
        if arr[j] <= 0:
            '''
            Start selecting from right margin.
            Since, All of them are <= 0, choosing numbers from right margin
            provides maximum product when they are multiplied.
            '''
            picked = []
            for x in range(N):
                picked.append(arr[j])
                j -= 1
            return None, picked
        else:
            '''
            choose the last and greatest one and decrease the counter.
            Now since number of elements to be choosen has become EVEN, Follow the algorithm for EVEN count.
            '''
            picked = pick_numbers_when_N_is_even(arr, length-1, N-1)
            picked.append(arr[length-1])
            return None, picked
    # When number of elements to be choosen is even
    return None, pick_numbers_when_N_is_even(arr, length, N)

if __name__ == '__main__':
    message = '\nPlease provide the input in the following format.\n\n'\
            'N K (N is number_of_elements, K is number of elements to be choosen)\n'\
            'N space seperated integer values in single line\n'
    print (message)
    try:
        temp1 = list(map(int, input().split()))
        number_of_elements, N = temp1[0], temp1[1]
        if number_of_elements == 0:
            print ('Number of elements in array are 0')
        elif number_of_elements < 0 or N < 0:
            print ('N or K can not be a negative number.')
        else :
            '''
            Just in case number of elements provide as input is greater than number_of_elements
            Choose the first `number_of_elements` numbers.
            '''
            arr = list(map(int, input().split()))[:number_of_elements]
            error, picked = pick_N_numbers(arr, number_of_elements, N)
            if error:
                print (error)
            elif picked:
                print ('The choosen %s numbers are ' % N, end=": ")
                print (*picked)
            else:
                print ('Something went wrong.')
    except ValueError:
        print ('Invalid Input format. Please try again.')
    except Exception as exc:
        print (exc)
