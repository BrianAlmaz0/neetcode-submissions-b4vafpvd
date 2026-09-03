class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False

        target = sum(nums) // 2
        dp = set()
        dp.add(0)

        for num in nums:
            nextDP = set()
            for currSum in dp:
                if target in dp:
                    return True
                nextDP.add(currSum)
                nextDP.add(currSum + num)
            dp = nextDP
        
        return True if target in dp else False