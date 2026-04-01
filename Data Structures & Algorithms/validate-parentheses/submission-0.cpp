class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';

        stack<char> stk;

        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            //if its a close parentheses
            if(map.find(c) != map.end()){
                if(!stk.empty() && map[c] == stk.top()){
                    stk.pop();
                } else{
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
