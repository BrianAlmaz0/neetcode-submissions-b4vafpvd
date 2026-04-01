class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(seen.find(diff) != seen.end()){
                ans.push_back(seen[diff]);
                ans.push_back(i);
                return ans;
            }
            seen[nums[i]] = i;
        }
        return ans;
    }
};