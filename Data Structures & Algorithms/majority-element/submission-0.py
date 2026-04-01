class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority = 0
        res = nums[0]

        for num in nums:
            if res == num:
                majority += 1
            else:
                majority -= 1
            
            if majority == 0:
                res = num
                majority = 1
        return res