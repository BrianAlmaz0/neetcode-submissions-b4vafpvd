class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longestStreak = 0;

        //itterate through the hashset
        for(int num : numSet){
            //if num - 1 isnt in the set then it's the start of a new sequenc
            if(numSet.find(num - 1) == numSet.end()){
                int currentNum = num;
                int currentStreak = 1;

                while(numSet.find(currentNum + 1) != numSet.end()){
                    currentStreak++;
                    currentNum++;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};