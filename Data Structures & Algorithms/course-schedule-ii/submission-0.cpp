class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);


        //b->a
        for(auto& p : prerequisites){
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();

            for(int nei : graph[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(res.size() != numCourses) return {};
        return res;
    }
};
