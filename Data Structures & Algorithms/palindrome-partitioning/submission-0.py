class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def isPalindrome(curr):
            l, r = 0, len(curr) - 1

            while l < r:
                if curr[r] != curr[l]:
                    return False
                
                r -= 1
                l += 1
            
            return True
        
        def backtrack(curr, i):
            if i == len(s):
                res.append(curr.copy())
                return

            #Check if substring is palindrome
            j = i + 1
            while j <= len(s):
                if isPalindrome(s[i:j]):
                    curr.append(s[i:j])
                    backtrack(curr, j)
                    curr.pop()
                j += 1

        backtrack([], 0)
        return res

            
        