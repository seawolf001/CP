



class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        if n==1: return ["1"]
        for x in range(1,n+1):
            check3 = x % 3 == 0
            check5 = x % 5 == 0
            if check3 and check5:
                ans.append("FizzBuzz")
            elif check3:
                ans.append("Fizz")
            elif check5:
                ans.append("Buzz")
            else:
                ans.append(str(x))
        return ans

