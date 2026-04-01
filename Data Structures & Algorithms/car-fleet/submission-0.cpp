class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> moves;
        for(int i = 0; i < position.size(); i++){
            moves.push_back({position[i], speed[i]});
        }

        sort(moves.begin(), moves.end());
        reverse(moves.begin(), moves.end());
        stack<double> stk;

        for(int i = 0; i < moves.size(); i++){
            double time =  double(target - moves[i][0]) / moves[i][1];

            if(!stk.empty() && time <= stk.top()){
                continue; // Car before will catch up and slow down to JOIN fleet
            }
            //If not, the car before wont ever catch up and FORM ITS OWN fleet
            stk.push(time);
        }
        return stk.size();
    }
};
