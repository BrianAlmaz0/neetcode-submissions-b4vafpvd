class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums) #count all freq of each num
        freq = [[] for i in range(len(nums) + 1)] #number of elements that appear index times

        for num, count in count.items():
            freq[count].append(num)
        
        ans = []
        for i in range(len(freq) - 1, -1, -1):
            for j in range(len(freq[i])):
                ans.append(freq[i][j])
                if len(ans) == k:
                    return ans


        