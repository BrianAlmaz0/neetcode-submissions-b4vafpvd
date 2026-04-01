class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r){
            int middle = (l + r) / 2;

            if(nums[middle] > nums[r]){
                l = middle + 1;
            } else if(nums[middle] <= nums[r]){
                r = middle;
            }
        }
        return nums[l];
    }
};