class Solution {
public:
    bool isPalindrome(string s) {
        //First we need to get only lowercase letters
        string copy = "";
        for(int i = 0; i < s.length(); i++){
            if(isalnum(s[i])){
                copy += tolower(s[i]);
            }
        }
        //Now that we have all lowercase letters we have to check first and last
        //index at the same time
        int length = copy.length();
        for(int i = 0; i < length / 2; i++){
            if(copy[i] != copy[length - i - 1]){
                return false;
            }
        }
        return true;
    }
};