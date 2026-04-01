class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int middle = (left + right) / 2;

            if(nums[middle] == target){
                return middle;
            } else if(nums[middle] < target){
                left = middle + 1;
            } else{
                right = middle - 1;
            }
        }
        return -1;
    }
    int findPivot(vector<int>& nums){
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int middle = (left + right) / 2;

            if(nums[middle] > nums[right]){
                left = middle + 1;
            } else{
                right = middle;
            }
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int pivot = findPivot(nums);

        if(target >= nums[pivot] && target <= nums[right]){
            return binarySearch(nums, pivot, right, target);
        } else{
            return binarySearch(nums, left, pivot - 1, target);
        }
        return - 1;
    }
};
