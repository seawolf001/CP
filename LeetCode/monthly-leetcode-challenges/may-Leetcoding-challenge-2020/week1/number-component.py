

class Solution:
    def findComplement(self, num: int) -> int:

        bits = num.bit_length()

        for x in range(bits):
            num = num ^ (1 << x)

        return num
