class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n , -1);
        return min(helper(cost, memo, n - 1), helper(cost, memo, n - 2));
    }

    int helper(vector<int>& cost, vector<int>& memo, int n){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        if(memo[n] != -1) return memo[n];

        memo[n] = cost[n] + min(helper(cost, memo, n - 1), helper(cost, memo, n-2));
        return memo[n];
    }
};
