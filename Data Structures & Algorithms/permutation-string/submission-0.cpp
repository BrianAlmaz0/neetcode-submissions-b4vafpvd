class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length();
        int left = 0;

        //Frequency count for s1;
        vector<int>target (26, 0);
        for(char c : s1){
            target[c - 'a']++;
        }
        
        vector<int> freq (26, 0);

        for(int right = 0; right < s2.length(); right++){
            freq[s2[right] - 'a']++;

            //if the window size is exceeded then we increase the left pointer
            // and decrease the freq counter from our window
            if(right - left + 1 > windowSize){
                freq[s2[left] - 'a']--;
                left++;
            }
            //if our target is the same as our freq and the window size is the same return true
            if(right  - left + 1 == windowSize && target == freq){
                return true;
            }
            
        }
        return false;
    }
};