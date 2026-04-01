class Solution {
public:
    void backtrack(int open, int close, string s, int n, vector<string>& result){
        if(s.length() == 2*n){
            result.push_back(s);
            return;
        }

        if(open < n){
            backtrack(open + 1, close, s + "(", n, result);
        }
        if(close < open){
            backtrack(open, close + 1, s + ")", n, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, "", n, result);
        return result;
    }
};
