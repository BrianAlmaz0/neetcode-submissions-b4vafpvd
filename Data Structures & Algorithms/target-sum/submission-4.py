class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = defaultdict(int)
        dp[0] = 1

        for i in range(len(nums)):
            nextDP = defaultdict(int)
            for currSum, ways in dp.items():
                nextDP[currSum + nums[i]] += ways
                nextDP[currSum - nums[i]] += ways
            dp = nextDP
        return dp[target]