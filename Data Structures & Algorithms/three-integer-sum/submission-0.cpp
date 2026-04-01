class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> vecSet;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            //Skip over duplicate i's
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            //Perform 2 ptr approach on that window
            int left = i + 1;
            int right = nums.size() - 1;
            int sum = 0;

            while(left < right){
                //Make left and right ptrs dont hit i
                if(left < right && left == i){
                    left++;
                }
                if(left < right && right == i){
                    right--;
                }

                //Calculate the sum
                sum = nums[left] + nums[right] + nums[i];
                //If it's 0 we add it to our set
                if(sum == 0){
                    vecSet.insert({nums[left], nums[right], nums[i]});
                }

                //continuation of 2 ptr approach
                if(sum < 0){
                    left++;
                } else{
                    right--;
                }
            }
        }
        for(auto entry : vecSet){
            ans.push_back(entry);
        }
        return ans;
    }
};
