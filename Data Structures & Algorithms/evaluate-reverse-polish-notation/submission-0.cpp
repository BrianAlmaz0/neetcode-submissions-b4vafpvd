class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();

                int output = 0;

                if(token == "+"){
                    output = num2 + num1;
                } else if(token == "-"){
                    output = num2 - num1;
                } else if(token == "*"){
                    output = num2 * num1;
                } else{
                    output = num2 / num1;
                }
                stk.push(output);
            } else{
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
