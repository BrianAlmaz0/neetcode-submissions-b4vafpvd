class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for(int i = 0; i < s.length(); i++){
            int right = i, left = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if((right - left + 1) > resLen){
                    resLen = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }

            left = i, right = i + 1;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                if((right - left + 1) > resLen){
                    resLen = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }
        return res;
    }
};
