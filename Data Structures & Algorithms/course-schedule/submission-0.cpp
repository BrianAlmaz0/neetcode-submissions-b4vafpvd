class Solution {
public:
    bool isThereCycle(int node, vector<vector<int>>& graph, vector<int>& state){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;  
        for(int nei : graph[node]){
            if(isThereCycle(nei, graph, state)) return true;
        }

        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto& p : prerequisites){
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
        }

        vector<int> state(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(isThereCycle(i, graph, state)) return false;
            }
        }
        return true;
    }
};
