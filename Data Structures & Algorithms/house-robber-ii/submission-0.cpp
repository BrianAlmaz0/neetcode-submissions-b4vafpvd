class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int rob1 = 0, rob2 = 0, maxx = 0;
        int temp;

        //0, n - 2
        for(int i = 0; i < nums.size() - 1; i++){
            temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        maxx = max(maxx, rob2);
        rob1 = 0, rob2 = 0;
        
        for(int i = 1; i < nums.size(); i++){
            temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return max(maxx, rob2);
    }
};
