class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        #Go through the list of strings
        for word in strs:
            length = len(word)
            res += str(length) + "#" + word
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0

        while i < len(s):
            num = 0

            while s[i] != "#":
                num = num * 10 + int(s[i])
                i += 1
            
            i += 1

            word = s[i : i+ num]            
            res.append(word)
            i += num
        
        return res