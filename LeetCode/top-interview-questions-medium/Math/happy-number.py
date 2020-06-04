


class Solution:
    '''
    '''
    def sum_of_squares_of_digits(self, num):
        s = 0
        while num:
            s += (num % 10) ** 2
            num  //= 10
        return s

    def isHappy(self, n: int) -> bool:
        s = set()
        while True:
            n = self.sum_of_squares_of_digits(n)
            if n == 1 : return True
            if n in s: return False
            s.add(n)

