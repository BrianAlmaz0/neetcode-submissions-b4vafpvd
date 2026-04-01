class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""

        for s in strs:
            res += str(len(s)) + "#" + s
        
        return res

    def decode(self, s: str) -> List[str]:
        res, i, = [], 0
        j = 0

        while i < len(s):
            j = i
            length = ""
            while s[j] != "#":
                length += s[j]
                j += 1
            
            res.append(s[j + 1 : j + 1 + int(length)])
            i = j + 1 + int(length)
        
        return res
                
                