class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int l = 0;
        int r = length - 1;

        int largestArea = 0;
        while(l < r){
            int currentArea = min(height[l], height[r]) * (r - l);
            largestArea = max(currentArea, largestArea);

            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }
        return largestArea;
    }
};