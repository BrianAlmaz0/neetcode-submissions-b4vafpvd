class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counter;

        for(int num : nums){
            counter[num]++;
        }

        for(auto entry : counter){
            if(entry.second != 1){
                return true;
            }
        }
        return false;
    }
};
