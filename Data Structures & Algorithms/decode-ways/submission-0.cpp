class Solution {
public:

    int helper(const string& s, unordered_map<int, int>& seen, int index){
        //If the current index we're at is a 0, return 0
        if(s[index] == '0') return 0;

        if(seen.count(index)){
            return seen[index];
        }

        //See if we reached the end
        if(index == s.length()){
            return 1;
        }

        //Recurse into 2 parts
        int sum = 0;
        //Decode from just 1 index
        if(index < s.length()){
            sum += helper(s, seen, index + 1);
        }

        //Decode from 2 indices
        if(index + 1 < s.length() && stoi(s.substr(index, 2)) <= 26 && stoi(s.substr(index, 2)) >= 10){
            sum += helper(s, seen, index + 2);
        }
        seen[index] = sum;
        return sum;
    }

    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        unordered_map<int, int> seen;

        return helper(s, seen, 0);
    }
};