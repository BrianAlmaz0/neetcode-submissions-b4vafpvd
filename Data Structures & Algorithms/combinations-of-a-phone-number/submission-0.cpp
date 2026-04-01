class Solution {
public:
    unordered_map<char, string> mapp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backtrack(vector<string>& res, string& curr, const string& digits, int i){
        if(i == digits.length()){
            res.push_back(curr);
            return;
        }

        string letters = mapp[digits[i]];
        for(char ch : letters){
            curr.push_back(ch);
            backtrack(res, curr, digits, i + 1);
            curr.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string curr = "";
        if(digits == ""){
            return {};
        }
        backtrack(res, curr, digits, 0);
        return res;
    }
};
