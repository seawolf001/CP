

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        if n > 0:
            s = [""]*2*n
            self._generate_parenthesis(s,0,n,0,0, ans)
            ans.sort()
        return ans

    def _generate_parenthesis(self, s, index, n, _open, _close, ans):
        if _close == n:
            ans.append("".join(s))
        else:
            if _open > _close:
                s[index] = ')'
                self._generate_parenthesis(s, index+1, n, _open, _close+1, ans)
            if _open < n:
                s[index] = '('
                self._generate_parenthesis(s, index+1, n, _open+1, _close, ans)
