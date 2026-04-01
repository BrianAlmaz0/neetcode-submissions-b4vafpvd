class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = {}

        for i, num in enumerate(nums):
            complement = target - num

            if complement in mapp:
                return ([mapp[complement], i])
            
            mapp[num] = i
        