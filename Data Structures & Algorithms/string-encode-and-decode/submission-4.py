class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""

        for word in strs:
            num = len(word)
            s = s + str(num) + "#" + word
        
        return s

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0

        while i < len(s):
            num = 0

            while s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            
            i += 1

            res.append(s[i : i + num])
            
            i += num
        
        return res