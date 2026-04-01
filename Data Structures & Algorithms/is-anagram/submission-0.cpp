class Solution {
public:
    bool isAnagram(string s, string t) {
        //Base case
        if(s.length() != t.length()){
            return false;
        }

        //sort the string so that the letters are in alphabetical order
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        //see if the letters match at each index
        for(int i = 0; i < t.size(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        //If we go through the whole loop and they all match then we could say true 
        return true;
    }
};
