class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans;

        while(left < right){
            int sum = numbers[left] + numbers[right];

            if(target == sum){
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }

            if(sum < target){
                left++;
            } else{
                right--;
            }
        }
        return ans;
    }
};
