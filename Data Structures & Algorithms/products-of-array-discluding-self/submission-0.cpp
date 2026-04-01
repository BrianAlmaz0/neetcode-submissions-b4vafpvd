class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> ans(length, 1);

        //Going forward
        int forward = 1;
        for(int i = 0; i < length; i++){
            //forward is the same as every number that came before it
            ans[i] *= forward;            
            forward *= nums[i];
        }

        //going backward
        int backward = 1;
        for(int i = length - 1; i >= 0; i--){
            ans[i] *= backward;
            backward *= nums[i];
        }
        return ans;
    }
};
