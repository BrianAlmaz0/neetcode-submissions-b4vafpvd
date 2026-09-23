class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        runningSum, res = 0, nums[0]

        for num in nums:
            if runningSum < 0:
                runningSum = 0 
            
            runningSum += num
            res = max(res, runningSum)

        return res