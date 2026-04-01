class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //We could sort the array that way we have all the dups together if any
        sort(nums.begin(), nums.end());

        //We could loop through the array and check the indices next to eachother
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                return true; //this means there's a duplicate
            }
        }
        return false;
    }
};
