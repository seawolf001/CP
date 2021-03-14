'''
Name : Jitendra Kumar
Email: jitendra.iitp@gmail.com
'''
def next_greater_element(arr, length):
    '''
    Print next greater element for every element in array.
    Print -1 if there is no as such greater than element in right side of the index.
    '''
    stack = []
    stack.append(arr[0])
    mapped_next_greater_elements = dict()

    for x in range(1, length):
        if len(stack) == 0:
            stack.append(arr[x])
            continue
        '''
        Print all the elements whose nextGreaterElement is arr[x]
        and pop them out of the stack since they have now been processed.
        '''
        while len(stack) != 0 and stack[len(stack)-1] < arr[x]:
            #  print (str(stack[len(stack)-1]) + ' --->' + str(arr[x]))
            mapped_next_greater_elements[stack[len(stack)-1]] = arr[x]
            stack.pop()
        '''
        Push arr[i] to the stack so that we can print nextGreaterElement for arr[x]
        while we process elements from arr[x+1] to arr[length-1].
        '''
        stack.append(arr[x])
    '''
    Stack is not empty if there were some elements pushed
    whose nextGreaterElement element was not found.
    Otherwise they would have been popped out at some stage.
    '''
    while len(stack) != 0:
        #  print (str(stack[len(stack)-1]) + ' ---> -1')
        mapped_next_greater_elements[stack[len(stack)-1]] = -1
        stack.pop()
    return mapped_next_greater_elements

if __name__ == '__main__':
    try:
        message = 'Please provide the input in the following format.\n\n'\
                'N (Number of elments in array)\n'\
                'N space seperated integer values in single line\n'
        print (message)
        number_of_elements = int(input())
        if number_of_elements < 1:
            print ('Number of elements needs to be greater that 0')
        else:
            # Input array elements
            '''
            Just in case number of elements provide as input is greater than number_of_elements
            Choose the first `number_of_elements` numbers.
            '''
            arr = list(map(int, input().split()))[:number_of_elements]
            mapped_next_greater_elements = next_greater_element(arr, number_of_elements)
            for number in arr:
                print (str(number) + ' ---> ' + str(mapped_next_greater_elements[number]))
    except ValueError:
        print ('Invalid Input format. Please try again.')
    except Exception as exc:
        print (exc)
