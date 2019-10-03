'''
Name : Jitendra Kumar
Email: jitendra.iitp@gmail.com
'''

def sort_the_boarding_passes(boarding_passes):
    '''
    Print the boarding_passes in a manner such that,
    You start from your source_city and complete your journey
    through all the cities all the way till the destination_city
    '''
    reverse_map = dict() #reverse map will contains the mapping in reverse.

    for source_city in boarding_passes:
        '''
        reversing the initial mapping.
        Example: boarding_passes['bangalore'] = 'delhi' ===> reverse_map['delhi'] = 'bangalore'
        '''
        dest_city = boarding_passes[source_city]
        reverse_map[dest_city] = source_city

    source_city = None

    for source in boarding_passes:
        if not source in reverse_map:
            '''
            The city which does not have a 'travel_from_city' entry in reverse map,
            Actually is the starting point because you are not going to that city from any other one.
            '''
            source_city = source
            break
    '''
    Now that, We have found our start city,
    Use the initial mapping to traverse the route till the END.
    '''

    city = source_city
    while city:
        if (not city) or (not city in boarding_passes):
            break;
        print (city + " ---> " + boarding_passes[city])
        city = boarding_passes[city] or None

if __name__ == '__main__':
    try:
        message = "\nPlease provide the input in following format.\n\n"\
                "N (number of passes)\n"\
                "source_city destination_city\n"\
                ".\n"\
                ".\n"\
                ".\nN times\n\n"
        print (message)
        '''
        Using dict() for hashing the boarding_passes
        dict() lookup is O(1)
        '''
        number_of_passes = int(input())
        boarding_passes = dict()
        for x in range(number_of_passes):
            '''
            Example: delhi goa
            '''
            temp = input().split()
            source_city = temp[0]
            dest_city = temp[1]
            boarding_passes[source_city] = dest_city
        '''
        Sort the boarding_passes from start city to end.
        '''
        sort_the_boarding_passes(boarding_passes)
    except Exception as exc:
        print (exc)
