
"""
You are given coins of different denominations and a total amount of money.
Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.
"""

class Solution:
    """"""
    def change(self, amount: int, coins: List[int]) -> int:
        """"""
        return self.change_recurr(amount, coins, len(coins))

    def change_recurr(self, V, coins, n):
        """"""
        if V == 0:
            # amount == 0 hence no change needed
            return 1
        elif V < 0:
            # Negative amount
            return 0
        elif n <= 0:
            # No coins
            return 0
        return (self.change_recurr(V, coins, n-1) + # Exclude nth coin
                self.change_recurr(V-coins[n-1], coins, n)) # include nth coin

    def change_dp(self, V, coins, n):
        """"""
        raise NotImplementedError
